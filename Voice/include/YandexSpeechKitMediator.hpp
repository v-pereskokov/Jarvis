#ifndef YANDEXSPEECHKITMEDIATOR_H
#define YANDEXSPEECHKITMEDIATOR_H

#pragma once

#include <string>
#include <sstream>
#include <vector>
#include "Mediator.hpp"
#include "../src/SpeechKit.cpp"

/*!
 * \namespace Jarvis
 * \brief Основной namespace для всего проекта
 */
namespace Jarvis {
  /*!
   * \namespace Mediator
   * \brief namespace для классов посредников
   */
  namespace Mediator {
#define methods
#define params
#define structs
    
    class YandexSpeechKitMediator : public Mediator {
      /*!
       * \using connection::Map map
       * \brief Определяет тип для отображения std::string -> std::string
       */
      using map = connection::Map;
      /*!
       * \using std::string stringVoice
       * \brief Определяет тип для строки, преобразованной из голоса
       */
      using stringVoice = std::string;
      /*!
       * \using std::string pathToConfigs
       * \brief Определяет тип для пути к конфигурациям
       */
      using pathToConfigs = std::string;
      
      private structs:
      struct SpeechKitConstants final {
        using configurationFile = std::string;
        using resultSentenceKeySpeechKit = std::string;
        using settingsKeySpeechKit = std::string;
        using settingsKeysSpeechKitYandex = std::vector<settingsKeySpeechKit>;
        
        static const configurationFile speechKitJson;
        static const resultSentenceKeySpeechKit resultSentenceKey;
        static const settingsKeysSpeechKitYandex keys;
      };
      
      public methods:
      YandexSpeechKitMediator() = default;
      ~YandexSpeechKitMediator() = default;
      
      void execute();
      
      stringVoice getSentenceVoice() const;
      
      private methods:
      /*!
       * \brief Статический метод для "общения" с сервером Яндекса
       */
      stringVoice sendToYandexSpeechKit();
      /*!
       * \brief Статический метод для "общения" получения данных с сервера Yandex
       * \param path Путь до конфигурационного файла
       * \return map Отображение вида std::string -> std::string
       */
      map getMapFromYandexSpeechKit(const pathToConfigs &path);
      private params:
      stringVoice _sentence{""};
    };
    
    const YandexSpeechKitMediator::SpeechKitConstants::configurationFile YandexSpeechKitMediator::SpeechKitConstants::speechKitJson{"../conf/speechkit.json"};
    const YandexSpeechKitMediator::SpeechKitConstants::resultSentenceKeySpeechKit YandexSpeechKitMediator::SpeechKitConstants::resultSentenceKey{"variant"};
    const YandexSpeechKitMediator::SpeechKitConstants::settingsKeysSpeechKitYandex YandexSpeechKitMediator::SpeechKitConstants::keys{"key", "uuid", "topic", "lang"};
  }
}

#endif // YANDEXSPEECHKITMEDIATOR_H
