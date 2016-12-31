#ifndef SPEECHKIT_H
#define SPEECHKIT_H

#pragma once

#include "../src/Transport.cpp"

/*!
 * \namespace Jarvis
 * \brief Основной namespace для всего проекта
 */
namespace Jarvis {
  /*!
   * \namespace connection
   * \brief Для сетевых подключений
   */
  namespace connection {
#define methods
#define params
#define structs
    
    /*! \class SpeechKit
     * \brief Класс для "общения" с сервером YandexSpeechKitCloud
     */
    class SpeechKit : public Transport {
      public methods:
      /*!
       * \brief Конструктор
       * \param path Путь до конфигурационного файла
       * \param yandexOptions Список нужных ключей для конфигурационного файла
       */
      SpeechKit(const Transport::jPath &path, const Transport::OptionsList::yandexOptions yandexOptions);
      /*!
       * \brief Деструктор
       */
      ~SpeechKit() = default;
      /*!
       * \brief Отправка данных
       * \return bool Подтверждение отправки
       */
      bool send() override;
      
      protected methods:
      /*!
       * \brief Задание параметров отправки
       */
      void setOptions() override;
      
      private methods:
      SpeechKit() = delete;
      SpeechKit(const SpeechKit &copy) = delete;
      SpeechKit & operator=(const SpeechKit &copy) = delete;
    };
  }
}

#endif // SPEECHKIT_H
