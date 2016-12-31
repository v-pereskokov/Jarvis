#ifndef SENTENCE_H
#define SENTENCE_H

#pragma once

#include <string>

/*!
 * \namespace Jarvis
 * \brief Основной namespace для всего проекта
 */
namespace Jarvis {
  
#define methods
#define params
  
  /*! \class Sentence
   * \brief Класс для работы с предложениями к Jarvis
   */
  class Sentence {
    /*!
     * \using std::string phrase
     * \brief Определяет тип для фразы
     */
    using phrase = std::string;
    
    public methods:
    /*!
     * \brief Конструктор
     * \param phrase Фраза
     */
    Sentence(const phrase &phrase);
    /*!
     * \brief Конструктор копирования
     * \param copy Копируемый объект
     */
    Sentence(const Sentence &copy);
    /*!
     * \brief Конструктор копирования
     * \param copy Копируемый объект
     */
    Sentence(Sentence &&copy);
    /*!
     * \brief Оператор копирования
     * \param copy Копируемый объект
     */
    Sentence & operator=(const Sentence &copy);
    /*!
     * \brief Оператор копирования
     * \param copy Копируемый объект
     */
    Sentence & operator=(Sentence &&copy);
    /*!
     * \brief Деструктор
     */
    ~Sentence() = default;
    /*!
     * \brief Метод добавления фразы
     * \param sentence Фраза
     */
    void setSentence(const Sentence &sentence);
    /*!
     * \brief Метод добавления фразы
     * \param phrase Фраза (строка)
     */
    void setSentence(const phrase &phrase);
    /*!
     * \brief Метод добавления фразы
     * \return Фраза (строка)
     */
    phrase getSentence() const;
    /*!
     * \brief Оператор сравнения
     * \param lhs Левый операнд
     * \param rhs Правый операнд
     * \return bool Результат сравнения
     */
    friend bool operator==(const Sentence &lhs, const Sentence &rhs);
    /*!
     * \brief Оператор сравнения
     * \param lhs Левый операнд
     * \param rhs Правый операнд
     * \return bool Результат сравнения
     */
    friend bool operator!=(const Sentence &lhs, const Sentence &rhs);
    /*!
     * \brief Оператор больше
     * \param lhs Левый операнд
     * \param rhs Правый операнд
     * \return bool Результат сравнения
     */
    friend bool operator>(const Sentence &lhs, const Sentence &rhs);
    /*!
     * \brief Оператор меньше
     * \param lhs Левый операнд
     * \param rhs Правый операнд
     * \return bool Результат сравнения
     */
    friend bool operator<(const Sentence &lhs, const Sentence &rhs);
    /*!
     * \brief Оператор больше или равно
     * \param lhs Левый операнд
     * \param rhs Правый операнд
     * \return bool Результат сравнения
     */
    friend bool operator>=(const Sentence &lhs, const Sentence &rhs);
    /*!
     * \brief Оператор меньше или равно
     * \param lhs Левый операнд
     * \param rhs Правый операнд
     * \return bool Результат сравнения
     */
    friend bool operator<=(const Sentence &lhs, const Sentence &rhs);
    
    private methods:
    Sentence() = delete;
    
    private params:
    phrase _phrase; /*!< Строка*/
  };
  
  bool operator==(const Sentence &lhs, const Sentence &rhs) {
    return lhs._phrase == rhs._phrase;
  }
  
  bool operator!=(const Sentence &lhs, const Sentence &rhs) {
    return lhs._phrase != rhs._phrase;
  }
  
  bool operator>(const Sentence &lhs, const Sentence &rhs) {
    return lhs._phrase > rhs._phrase;
  }
  
  bool operator<(const Sentence &lhs, const Sentence &rhs) {
    return lhs._phrase < rhs._phrase;
  }
  
  bool operator>=(const Sentence &lhs, const Sentence &rhs) {
    return !(lhs < rhs);
  }
  
  bool operator<=(const Sentence &lhs, const Sentence &rhs) {
    return !(lhs > rhs);
  }
  
}

#endif // SENTENCE_H
