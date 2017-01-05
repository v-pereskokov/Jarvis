#include "../include/YandexSpeechKitMediator.hpp"

namespace Jarvis {
  namespace Mediator {
    void YandexSpeechKitMediator::execute() {
      _sentence = sendToYandexSpeechKit();
    }
    
    YandexSpeechKitMediator::stringVoice YandexSpeechKitMediator::getSentenceVoice() const {
      return _sentence;
    }
    
    YandexSpeechKitMediator::stringVoice YandexSpeechKitMediator::sendToYandexSpeechKit() {
      return getMapFromYandexSpeechKit(SpeechKitConstants::speechKitJson)[SpeechKitConstants::resultSentenceKey];
    }
    
    YandexSpeechKitMediator::map YandexSpeechKitMediator::getMapFromYandexSpeechKit(const pathToConfigs &path) {
      using namespace std;
      using responseString = string;
      
      connection::SpeechKit toYandex(path, SpeechKitConstants::keys);
      toYandex.send();
      responseString response(toYandex.recv());
      response.erase(response.begin(), response.begin() + response.find("<"));
      stringstream stream;
      stream << response;
      return map(connection::parsingTree(xmlParse(stream)));
    }
  }
}
