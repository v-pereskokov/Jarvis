#include <iostream>
#include <string>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
using namespace boost::asio;

io_service service;

class ToClient :
	public boost::enable_shared_from_this<ToClient>{
public:
	typedef boost::shared_ptr<ToClient> ptr;
	typedef boost::system::error_code error_code;
	ToClient() : sock_(service), started_(false) {}
	void start() { 
		started_ = true; 
		do_read(); 
	}
	void stop();
	static ptr new_() {
		ptr new_(new ToClient);
		return new_;
	}
	ip::tcp::socket &sock() {
		 return sock_;
	}
	void on_read(const error_code &err, size_t bytes);
	void on_write(const error_code &err, size_t bytes);
	void do_read();
	void do_write(const std::string &msg);
	size_t read_complete(const error_code &err, size_t bytes);
private:
	ip::tcp::socket sock_;
	char readBuf_[1024];
	char writeBuf_[1024];
	bool started_;
};

void ToClient::stop() {
	if (!started_)
		return;
	started_ = false;
	sock_.close();
}
void ToClient::on_read(const error_code &err, size_t bytes) {
	if (!err) {
		std::string msg(readBuf_, bytes);
		do_write(msg + '\n');
	}
	stop();	
}
void ToClient::on_write(const error_code &err, size_t bytes) {
	do_read();
}
void ToClient::do_read() {
	async_read(sock_, buffer(readBuf_),
		boost::bind(&ToClient::read_complete, shared_from_this(), _1, _2),
		boost::bind(&ToClient::on_read, shared_from_this(), _1, _2));
}
void ToClient::do_write(const std::string &msg) {
	std::copy(msg.begin(), msg.end(), writeBuf_);
	sock_.async_write_some(buffer(writeBuf_, msg.size()),
		boost::bind(&ToClient::on_write, shared_from_this(), _1, _2));
}
size_t ToClient::read_complete(const error_code &err, size_t bytes) {
	if (err)
		return 1;
	bool find_ = std::find(readBuf_, readBuf_ + bytes, '\n') < readBuf_ + bytes;
	return find_ ? 0 : 1;
}

ip::tcp::acceptor acceptor(service, ip::tcp::endpoint(ip::tcp::v4(), 8000));

void handle_accept(ToClient::ptr client, const ToClient::error_code &err) {
	client->start();
	ToClient::ptr newClient = ToClient::new_();
	acceptor.async_accept(newClient->sock(),
		boost::bind(handle_accept, newClient, _1));
}

int main() {
	ToClient::ptr client = ToClient::new_();
	acceptor.async_accept(client->sock(),
	boost::bind(handle_accept, client, _1));
	service.run();
	return 0;
}
