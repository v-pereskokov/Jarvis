#pragma once

#ifndef COMMAND_H
#define COMMAND_H

#include <cstdlib>
#include <vector>
#include <string>
#include <initializer_list>

/*!
 * \namespace Jarvis
 * \brief Основной namespace для всего проекта
 */
namespace Jarvis {
  /*!
   * \namespace Commands
   * \brief namespace для хранения всего, что связано с выполнением команд
   */
  namespace Commands {
    /*!
     * \namespace CommandType
     * \brief Хранение констант - основных типов команд
     */
    namespace CommandType{
      using commandType = std::string;
      
      const commandType python = "python";
      const commandType shell = "";
      const commandType music = "afplay";
    }
    
#define methods
#define params
    
    /*! \class Command
     * \brief Класс, отвечающий за выполнение команд
     */
    class Command final {
      /*!
       * \using std::string scriptName
       * \brief Определяет тип для имени скрипта
       */
      using scriptName = std::string;
      /*!
       * \using std::string argument
       * \brief Определяет тип для одного аргумента скрипта
       */
      using argument = std::string;
      /*!
       * \using std::initializer_list<argument> argumentsList
       * \brief Определяет тип для списка инициализации аргументов скрипта
       */
      using argumentsList = std::initializer_list<argument>;
      /*!
       * \using std::vector<argument> argumentsVector
       * \brief Определяет тип для вектора аргументов скрипта
       */
      using argumentsVector = std::vector<argument>;
      /*!
       * \using std::string executeCommand
       * \brief Определяет тип для запускаемой команды
       */
      using executeCommand = std::string;
      
    public:
      /*!
       * \brief Подготовка и отправка данных
       * \param type Тип скрипта
       * \param script Название скрипта
       * \param arguments Список аргументов скрипта (по умолчанию пустой)
       * Cтатический метод сбора данных и запуска команды
       */
      static void execute(const CommandType::commandType &type, const scriptName &script, const argumentsList arguments = {});
      
    private:
      /*!
       * \brief Запускает команду
       * \param arguments Список всех параметров, передаваемых для запуска команды
       * Cтатический метод для запуска скрипта
       */
      static void terminalExecute(const argumentsVector &arguments);
    };
  }
}

#endif // COMMAND_H
