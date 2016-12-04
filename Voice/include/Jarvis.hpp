#ifndef JARVIS_H
#define JARVIS_H

#pragma once

#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <thread>
#include <boost/utility.hpp>
#include "../src/Command.cpp"
#include "../src/SerialPort.cpp"
#include "../src/SpeechKit.cpp"
#include "../src/Voice.cpp"

/*!
 * \namespace Jarvis
 * \brief Основной namespace для всего проекта
 */
namespace Jarvis {
#define methods
#define params
#define structs
  
  /*! \class Jarvis
   * \brief Класс, описывающий аналог ИИ
   */
  class Jarvis : boost::noncopyable {
    /*!
     * \using connection::Map map
     * \brief Определяет тип для отображения std::string -> std::string
     */
    using map = connection::Map;
    /*!
     * \using Arduino::Connection::SerialPort SerialPort
     * \brief Определяет тип для порта I/O
     */
    using SerialPort = Arduino::Connection::SerialPort;
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
    /*!
     * \using std::string sayPhrase
     * \brief Определяет тип для фразы, которую система должна произнести
     */
    using sayPhrase = std::string;
    
    public methods:
    /*!
     * \brief Инициализация системы
     * \return Jarvis возвращает тип едиснтвенного объека Jarvis
     * Метод для инициализации системы
     */
    static Jarvis& instance();
    /*!
     * \brief Воспроизведение фразы
     * \param voice Голос Jarvis
     * \param phrase Фраза, которую Jarvis должен вопроизвести голосом
     * Метод для воспроизведения фразы, которую должен сказать Jarvis
     */
    static void say(Voice &voice, const sayPhrase &phrase);
    /*!
     * \brief Статический метод для запуска скрипта
     * \return stringVoice Строка, преобразованная из голоса
     */
    static stringVoice toArduino();
    
    private methods:
    /*!
     * \brief Конструктор по-умолчанию
     */
    Jarvis() = default;
    /*!
     * \brief Конструктор
     * \param voice Голос Jarvis'a
     */
    Jarvis(Voice &voice);
    /*!
     * \brief Деструктор
     */
    ~Jarvis() = default;
    Jarvis(const Jarvis &copy) = delete;
    Jarvis(Jarvis &&copy) = delete;
    Jarvis & operator=(const Jarvis &copy) = delete;
    Jarvis & operator=(Jarvis &&copy) = delete;
    friend struct JarvisDestroyer;
    /*!
     * \brief Статический метод для "общения" с сервером Яндекса
     * \return stringVoice Строка, преобразованная из голоса
     */
    static stringVoice sendToYandexSpeechKit();
    /*!
     * \brief Статический метод для "общения" с портом Arduino
     * \param serial Порт, по которому будет отправлен сигнал
     * \param command Команда, которая будет отправлена
     */
    static void sendToSerialPort(SerialPort &serial, const std::string &command);
    /*!
     * \brief Статический метод для "общения" получения данных с сервера Yandex
     * \param path Путь до конфигурационного файла
     * \return map Отображение вида std::string -> std::string
     */
    static map getMapFromYandexSpeechKit(const pathToConfigs &path);
    
    private structs:
    /*! \struct JarvisDestroyer
     * \brief Класс, описывающий аналог ИИ
     */
    struct JarvisDestroyer : boost::noncopyable {
      public methods:
      /*!
       * \brief Конструктор по-умолчанию
       */
      JarvisDestroyer() = default;
      /*!
       * \brief Деструктор
       */
      ~JarvisDestroyer();
      /*!
       * \brief Инициализация системы
       * \param jarvis Объект Jarvis
       * Метод для инициализации системы
       */
      void initialize(Jarvis *jarvis);
      
      private methods:
      JarvisDestroyer(const JarvisDestroyer &copy) = delete;
      JarvisDestroyer(JarvisDestroyer &&copy) = delete;
      JarvisDestroyer & operator=(const JarvisDestroyer &copy) = delete;
      JarvisDestroyer & operator=(JarvisDestroyer &&copy) = delete;
      
      private params:
      Jarvis *_jarvis; /*!< Объект Jarvis*/
    };
    
    private params:
    static Jarvis *_jarvis; /*!< Статический объект Jarvis*/
    static JarvisDestroyer _destroyer; /*!< Статический объект, отвечающий за разрушение Jarvis'a*/
    Voice _voice; /*!< Голос Jarvis*/
  };
    
}

#endif // JARVIS_H
