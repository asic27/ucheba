/** @file
 * @author Асаян А.В.
 * @version 1.0
 * @date 28.05.2019
 * @copyright ИБСТ ПГУ
 * @warning Работа студента.
 * @brief Заголовочный файл для модуля Perestanovka
 */
#pragma once
#include <string>
#include <stdexcept>
/** @brief Шифрование методом табличной маршрутной перестановки.
 * @details Ключ устанавливается в конструкторе.
 * Для зашифровывания и расшифровывания предназначены методы shifr и rashifr.
 * @warning Реализация только для английского языка.
 */
class Perestanovka{
private:
    int k;///< Ключ
    std::string getValidOpenText(const std::string & s);///< Метод проверки открытого текста.
    std::string getValidCipherText(const std::string & s);///< Метод проверки зашифрованного текста.
public:
/** @brief Конструктор без параметра.
 * @details Конструктор запрещён.
 */
    Perestanovka()=delete;
/** @brief Конструктор для установки ключа.
 * @param [in] k - ключ, целое, положительное число.
 * @throw cipher_error, если ключ меньше или равен 1.
 */
    Perestanovka(const int k);
/**
 * @brief Метод для шифрования текста методом маршрутной табличной перестановки. 
 * @details Запись в таблицу происходит слева направо, сверху вниз. Считывание из таблицы сверху вниз, справа налево
 * @param [in] t Открытый текст. Не должен быть пустой строкой. Текст не должен быть меньше или равен длине ключа. Все не-буквы будут автоматически удалены.
 * @return Зашифрованный текст. 
 * @throw cipher_error, если строка пустая или меньше или равна длине ключа.
 */
    std::string  shifr(const std::string& t);
/**
 * @brief Метод для расшифровки зашифрованного текста по известному ключу.
 * @param [in] z Зашифрованный текст. Должен содержать только символы английского алфавита в верхнем регистре. Строка не должна быть пустой.
 * @return Расшифрованный текст.
 * @throw cipher_error, если строка пустая или встречена не английская буква в верхнем регистре.
 */
    std::string  rashifr(const std::string& z); 
};

class cipher_error: public std::invalid_argument
{
public:
    explicit cipher_error (const std::string& what_arg):
        std::invalid_argument(what_arg) {}
    explicit cipher_error (const char* what_arg):
        std::invalid_argument(what_arg) {}
};