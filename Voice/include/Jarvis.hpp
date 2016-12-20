#ifndef JARVIS_H
#define JARVIS_H

#pragma once

#include <vector>
#include <map>
#include <string>
#include <thread>
#include <memory>
#include <boost/utility.hpp>
#include "../src/Command.cpp"
#include "../src/SerialPort.cpp"
#include "Mediator.hpp"
#include "../src/YandexSpeechKitMediator.cpp"
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
     * \using std::string sayPhrase
     * \brief Определяет тип для фразы, которую система должна произнести
     */
    using sayPhrase = std::string;
    using mediator = Mediator::Mediator;
    using mediator_ptr = std::shared_ptr<mediator>;
    using mediatorName = std::string;
    using mediators = std::map<mediatorName, mediator_ptr>;
    
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
    
    static void initializeMediators(mediators &mediators);
    
    static mediator_ptr getMediator(const mediatorName &name);
    /*!
     * \brief Статический метод для "общения" с портом Arduino
     * \param serial Порт, по которому будет отправлен сигнал
     * \param command Команда, которая будет отправлена
     */
    static void sendToSerialPort(SerialPort &serial, const std::string &command);
    
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
    
    template <typename... Exact>
    struct funptr {
      template <typename R>
      constexpr auto operator()(R(*pointer)(Exact...)) -> decltype(pointer) {
        return pointer;
      }
    };
    
    private params:
    static Jarvis *_jarvis; /*!< Статический объект Jarvis*/
    static JarvisDestroyer _destroyer; /*!< Статический объект, отвечающий за разрушение Jarvis'a*/
    Voice _voice; /*!< Голос Jarvis*/
    static mediators _mediators; /*!< Посредники*/
  };
  
}

#endif // JARVIS_H
