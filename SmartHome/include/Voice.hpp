#ifndef VOICE_H
#define VOICE_H

#pragma once

#include <string>
#include "../src/Sentence.cpp"
#include "../src/Command.cpp"

/*!
 * \namespace Jarvis
 * \brief Основной namespace для всего проекта
 */
namespace Jarvis {
#define methods
#define params
  
  /*! \class Voice
   * \brief Описывает объект голос
   */
  class Voice final {
    /*!
     * \using connection::Map map
     * \brief Определяет тип для отображения std::string -> std::string
     */
    using map = connection::Map;
    /*!
     * \using std::string path
     * \brief Определяет тип для пути до конфигурационного файла
     */
    using path = std::string;
    /*!
     * \using std::string name
     * \brief Определяет тип для имени объекта, который имеет голос
     */
    using name = std::string;
    
    public methods:
    /*!
     * \brief Конструктор
     * \param path Путь до конфигурационного файла
     * \param name Имя голоса
     */
    Voice(const path &path, const name &name);
    /*!
     * \brief Деструктор
     */
    ~Voice() = default;
    /*!
     * \brief Конструктор копирования
     * \param copy Копируемый объект
     */
    Voice(const Voice &copy) = default;
    /*!
     * \brief Конструктор копирования
     * \param copy Копируемый объект
     */
    Voice(Voice &&copy) = default;
    /*!
     * \brief Конструктор копирования
     * \param copy Копируемый объект
     */
    Voice & operator=(const Voice &copy) = default;
    /*!
     * \brief Конструктор копирования
     * \param copy Копируемый объект
     */
    Voice & operator=(Voice &&copy) = default;
    /*!
     * \brief Конструктор копирования
     * \return bool Подтверждение - была ли сказана фраза
     */
    bool say();
    /*!
     * \brief Метод изменения фразы
     * \param sentence Предложение
     */
    void setSentence(const Sentence &sentence);
    /*!
     * \brief Метод получения фразы
     * \return sentence Предложение
     */
    Sentence getSentence() const;
    
    private methods:
    Voice() = delete;
    /*!
     * \brief Метод запуска воспроизведения голоса
     * \return bool Проверка - запустилось ли
     */
    bool execute();
    /*!
     * \brief Метод нахождения нужной команды
     * \param waves Сэмплы
     * \param sentence Фраза
     * \return bool Найдено ли
     */
    bool findCommand(const connection::Map &waves, const Sentence &sentence);
    
    private params:
    name _name; /*!< Имя голоса*/
    map _waves; /*!< Необходимый сэмпл*/
    Sentence _sentence; /*!< Фраза*/
  };
}

#endif // VOICE_H
