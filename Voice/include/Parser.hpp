#ifndef PARSER_H
#define PARSER_H

#pragma once

#include <string>
#include <sstream>
#include <map>
#include <boost/property_tree/ptree.hpp>

/*!
 * \namespace Jarvis
 * \brief Основной namespace для всего проекта
 */
namespace Jarvis {
#define methods
#define params
#define usings
  using boost::property_tree::ptree;
  
  /*! \class Parser
   * \brief Класс для парсинга файлов различных типов
   */
  class Parser final {
    public usings:
    /*!
     * \using ptree Tree
     * \brief Определяет тип для дерева
     */
    using Tree = ptree;
    /*!
     * \using std::stringstream stringTarget
     * \brief Определяет тип для потока
     */
    using stringTarget = std::stringstream;
    /*!
     * \using std::string Path
     * \brief Определяет тип для пути к файлу
     */
    using Path = std::string;
    
    public methods:
    /*!
     * \brief Конструктор по-умолчанию
     */
    Parser() = default;
    /*!
     * \brief Конструктор
     * \param path Путь до файла
     */
    explicit Parser(const Path &path);
    /*!
     * \brief Конструктор копирования
     */
    Parser(const Parser &copy) = default;
    /*!
     * \brief Оператор копирования
     */
    Parser & operator=(const Parser &copy) = default;
    /*!
     * \brief Деструктор
     */
    ~Parser() = default;
    /*!
     * \brief Метод для подгрузки файла
     * \param path Путь до файла
     */
    void loadTarget(const Path &path);
    /*!
     * \brief Парсер json фалйа
     * \return Дерево, распарсенного файла
     */
    Tree jsonParse();
    /*!
     * \brief Парсер json фалйа
     * \return Дерево, распарсенного файла
     */
    friend Tree jsonParse(stringTarget &stream);
    /*!
     * \brief Парсер xml фалйа
     * \return Дерево, распарсенного файла
     */
    Tree xmlParse();
    /*!
     * \brief Парсер xml фалйа
     * \return Дерево, распарсенного файла
     */
    friend Tree xmlParse(stringTarget &stream);
    
    private params:
    Path _target; /*!< путь до файла*/
    Tree _tree; /*!< Дерево*/
  };
  
  Parser::Tree jsonParse(Parser::stringTarget &stream) {
    Parser::Tree tree;
    read_json(stream, tree);
    return tree;
  }
  
  Parser::Tree xmlParse(Parser::stringTarget &stream) {
    Parser::Tree tree;
    read_xml(stream, tree);
    return tree;
  }
}

#endif // PARSER_H
