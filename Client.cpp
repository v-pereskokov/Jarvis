#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

using namespace boost::asio;

io_service service;

class ToServer:
	public boost::enable_shared_from_this<ToServer> {
public:
	typedef boost::shared_ptr<ToServer> ptr;
	typedef boost::system::error_code error_code;
	ToServer(const std::string &msg) : sock_(service), started_(true), msg_(msg) {}
	void start(ip::tcp::endpoint ep);
	static ptr startClient(ip::tcp::endpoint ep, const std::string &msg) {
		ptr new_(new ToServer(msg));
		new_->start(ep);
		return new_;
	}
	void stop();
	void on_connect(const error_code &err);
	void on_read(const error_code &err, size_t bytes);
	void on_write(const error_code &err, size_t bytes);
	void do_read();
	void do_write(const std::string &msg);
	size_t read_complete(const error_code &err, size_t bytes);
private:
	bool started_;
	char readBuf_[1024];
	char writeBuf_[1024];
	std::string msg_;
	ip::tcp::socket sock_;
};

void ToServer::start(ip::tcp::endpoint ep) {
	sock_.async_connect(ep, boost::bind(&ToServer::on_connect,
		shared_from_this(), _1));
}
void ToServer::stop() {
	if (!started_)
		return;
	started_ = false;
	sock_.close();
}
void ToServer::on_connect(const error_code &err) {
	if (!err)
		do_write(msg_ + '\n');
	else
		stop();
}
void ToServer::on_read(const error_code &err, size_t bytes) {
	if (!err) {
		std::string copy_str(readBuf_, bytes - 1);
		std::cout << "Echo-Server answered - "
		<< (copy_str == msg_ ? "WELL\n" : "WRONG\n")
		<< "Server massage_: "
		<< copy_str << std::endl;
	}
	stop();
}
void ToServer::on_write(const error_code &err, size_t bytes) {
	do_read();
}
void ToServer::do_read() {
	async_read(sock_, buffer(readBuf_),
		boost::bind(&ToServer::read_complete, shared_from_this(), _1, _2),
		boost::bind(&ToServer::on_read, shared_from_this(), _1, _2));
}
void ToServer::do_write(const std::string &msg) {
	if (!started_)
		return;
	std::copy(msg.begin(), msg.end(), writeBuf_);
	sock_.async_write_some(buffer(writeBuf_, msg.size()), 
		boost::bind(&ToServer::on_write, shared_from_this(), _1, _2));
}
size_t ToServer::read_complete(const error_code &err, size_t bytes) {
	if (err)
		return 1;
	bool find_ = std::find(readBuf_, readBuf_ + bytes, '\n') < readBuf_ + bytes;
	return find_ ? 0 : 1;
}

int main() {
	ip::tcp::endpoint ep(ip::address::from_string("127.0.0.1"), 8000);
	std::string massage;
	getline(std::cin, massage);
	ToServer::startClient(ep, massage);
	service.run();
	return 0;
}
