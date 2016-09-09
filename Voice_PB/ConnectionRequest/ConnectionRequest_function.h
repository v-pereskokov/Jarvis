#include <boost/shared_ptr.hpp>
#include "ConnectionRequest.pb.h"

namespace Jarvis
{
    
    namespace type_e = boost::type_erasure;
    
    // Init settings
    bool setting_init(std::vector<std::string> &settings, const int argc, char *argv[])
    {
        if (argc == 8) {
            for (std::size_t i = 2; i < argc; ++i)
                settings.push_back(static_cast<std::string>(argv[i]));
            return true;
        }
        return false;
    }
    
    // Setup ConnectionRequest
    bool setup(const std::vector<std::string> &settings, boost::shared_ptr<ConnectionRequest> CR)
    {
        if (settings.size() == 6) {
            CR->set_protocolversion(1);
            CR->set_speechkitversion("");
            CR->set_servicename("asr.yandex.net");
            CR->set_uuid(settings[0]);
            CR->set_apikey(settings[1]);
            CR->set_applicationname(settings[2]);
            CR->set_device(settings[3]);
            CR->set_coords("0, 0");
            CR->set_topic("queries");
            CR->set_lang(settings[4]);
            CR->set_format(settings[5]);
            return true;
        }
        return false;
    }
    
}