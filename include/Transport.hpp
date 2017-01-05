#pragma once

#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <cstdio>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <memory>
#include <algorithm>
#include <curl/curl.h>
#include "Parser.hpp"

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
#define usings
    
    /*!
     * \using std::string key
     * \brief Определяет тип для ключа
     */
    using Key = std::string;
    /*!
     * \using std::string data
     * \brief Определяет тип для значения
     */
    using Data = std::string;
    /*!
     * \using std::map<Key, Data> Map
     * \brief Определяет тип для отображения std::string -> std::string
     */
    using Map = std::map<Key, Data>;
    /*!
     * \using char* char_ptr
     * \brief Определяет тип для указателя на char
     */
    using char_ptr = char *;
    /*!
     * \using void* void_ptr
     * \brief Определяет тип для указателя на void
     */
    using void_ptr = void *;
    
    /*!
     * \brief Функция для отправки данных на сервер
     * \param pChar Указатель на тип данных
     * \param size Размер данных
     * \param count Колчиество отправляемых данных на сервер
     * \param pUserdata Данные пользователя
     * \return size_t Число отправленный байт
     */
    size_t writeResponseData(char_ptr pChar, size_t size, size_t count, void_ptr pUserdata);
    /*!
     * \brief Функция для получения данных с сервера
     * \param pChar Указатель на тип данных
     * \param size Размер данных
     * \param count Колчиество отправляемых данных на сервер
     * \param pUserdata Данные пользователя
     * \return size_t Число полученных байт
     */
    size_t readRequestData(char_ptr pChar, size_t size, size_t count, void_ptr pUserdata);
    /*!
     * \brief Парсинг дерева с данными
     * \param tree Дерево с данными
     * \return Map Отображение вида std::string -> std::string
     */
    Map parsingTree(const Jarvis::Parser::Tree &tree);
    
    /*! \class Transport
     * \brief Абстрактный класс для "общения" с сервером
     */
    class Transport {
      protected usings:
      /*!
       * \using CURL socket
       * \brief Определяет тип для сокета
       */
      using socket = CURL;
      /*!
       * \using CURLcode codeInfo
       * \brief Определяет тип для возвращаемого с сервера кода ответа
       */
      using codeInfo = CURLcode;
      /*!
       * \using curl_slist headerList
       * \brief Определяет тип для заголовков, отправляемых на сервер
       */
      using headerList = curl_slist;
      /*!
       * \using std::string jPath
       * \brief Определяет тип для пути до конфигурационного файла
       */
      using jPath = std::string;
      /*!
       * \using std::stringstream response
       * \brief Определяет тип для потока возвращаемых с сервера данных
       */
      using response = std::stringstream;
      /*!
       * \using std::string responseString
       * \brief Определяет тип для строки, преобразованной из потока
       */
      using responseString = std::string;
      /*!
       * \using std::ifstream file
       * \brief Определяет тип для файла
       */
      using file = std::ifstream;
      
      public structs:
      /*! \class OptionsList
       * \brief Данные, необходимые для отправки данных
       */
      struct OptionsList {
        friend class Transport;
        
        /*!
         * \using std::string yandexOption
         * \brief Определяет тип для параметра
         */
        using yandexOption = std::string;
        /*!
         * \using std::map<std::string, std::string> jList
         * \brief Определяет тип для отображения std::string -> std::string
         */
        using jList = std::map<std::string, std::string>;
        /*!
         * \using std::string url
         * \brief Определяет тип для URL
         */
        using url = std::string;
        /*!
         * \using std::string option
         * \brief Определяет тип для имени параметра
         */
        using option = std::string;
        /*!
         * \using std::string optionValue
         * \brief Определяет тип для значения параметра
         */
        using optionValue = std::string;
        /*!
         * \using std::map<std::string, std::string> optionList
         * \brief Определяет тип для отображения параметров
         */
        using optionList = std::map<std::string, std::string>;
        /*!
         * \using std::vector<yandexOption> yandexOptions
         * \brief Определяет тип для списка ключей
         */
        using yandexOptions = std::vector<yandexOption>;
        
        public methods:
        /*!
         * \brief Конструктор
         * \param path Путь до конфигурационного файла
         * \param yandexOptions Список с необходимыми ключами
         */
        explicit OptionsList(const jPath &path, const yandexOptions yandexOptions);
        /*!
         * \brief Метод получения значения параметра
         * \param option Искомый параметр
         * \return optionValue Значение заданного параметра
         */
        optionValue getOption(const option &option);
        /*!
         * \brief Деструктор
         */
        ~OptionsList() = default;
        
        private methods:
        OptionsList() = delete;
        OptionsList(const OptionsList &copy) = delete;
        OptionsList & operator=(const OptionsList &copy) = delete;
        /*!
         * \brief Метод заполнения списка параметров
         * \param list Отображение из распарсенного дерева
         */
        void fillList(const jList &list);
        /*!
         * \brief Метод составления URL'а из ключей и их значений для post запроса
         * \param list Отображение из распарсенного дерева
         * \param url Сырой url
         * \return url URL для отправки
         */
        url makeUrl(const jList &list, url &url);
        /*!
         * \brief Метод поиска ключевых параметров
         * \param option Искомый параметр
         * \return bool Подтверждение - найдено ли
         */
        bool findYandexOption(const yandexOption &option);
        
        protected params:
        optionList _optList; /*!< Список параметров*/
        
        private params:
        yandexOptions _yandexOptions; /*!< Список ключевых параметров*/
      };
      
      /*!
       * \using OptionsList property
       * \brief Определяет тип для параметров отправки
       */
      using property = OptionsList;
      
      public methods:
      /*!
       * \brief Конструктор
       * \param path Путь до конфигурационного файла
       * \param yandexOptions Список нужных ключей для конфигурационного файла
       */
      explicit Transport(const jPath &path, const OptionsList::yandexOptions yandexOptions);
      /*!
       * \brief Деструктор
       */
      virtual ~Transport();
      /*!
       * \brief Отправка данных
       * \return bool Подтверждение отправки
       */
      virtual bool send() = 0;
      /*!
       * \brief Получение данных
       * \return responseString Полученное сообщение
       */
      responseString recv() const;
      /*!
       * \brief Соединение
       * \return bool Подтверждение соединения
       */
      bool connect();
      /*!
       * \brief Проверка соединения
       * \return bool Подтверждение соединения
       */
      bool isConnect() const;
      
      protected methods:
      /*!
       * \brief Проверка соединения
       * \param curl Сокет для проверки
       * \return bool Подтверждение соединения
       */
      bool checkConnection(const socket *curl) const;
      /*!
       * \brief Задание параметров отправки
       */
      virtual void setOptions() = 0;
      
      private methods:
      Transport() = delete;
      Transport(const Transport &copy) = delete;
      Transport & operator=(const Transport &copy) = delete;
      
      protected params:
      socket *_curl; /*!< Сокет*/
      property _properties; /*!< Параметры соединения*/
      headerList *_headers; /*!< Заголовки*/
      response _response; /*!< Ответ с сервера*/
    };
  }
}

#endif // TRANSPORT_H
