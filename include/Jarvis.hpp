#pragma once

#ifndef JARVIS_H
#define JARVIS_H

#include <vector>
#include <map>
#include <string>
#include <thread>
#include <memory>
#include <utility>
#include <boost/utility.hpp>
#include "Command.hpp"
#include "Voice.hpp"

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
     * \using std::string stringVoice
     * \brief Определяет тип для строки, преобразованной из голоса
     */
    using stringVoice = std::string;
    /*!
     * \using std::string sayPhrase
     * \brief Определяет тип для фразы, которую система должна произнести
     */
    using sayPhrase = std::string;
    using bitsFromSmartHome = std::string;
    
    public methods:
    /*!
     * \brief Инициализация системы
     * \return Jarvis возвращает тип едиснтвенного объека Jarvis
     * Метод для инициализации системы
     */
    static Jarvis& instance();
    static stringVoice getStringVoice();
    
    private methods:
    /*!
     * \brief Конструктор по-умолчанию
     */
    Jarvis() = default;
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
     * \brief Воспроизведение фразы
     * \param voice Голос Jarvis
     * \param phrase Фраза, которую Jarvis должен вопроизвести голосом
     * Метод для воспроизведения фразы, которую должен сказать Jarvis
     */
//    static void say(Voice &voice, const sayPhrase &phrase);
    
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
    static Voice _voice; /*!< Голос Jarvis*/
  };
  
}

#endif // JARVIS_H
