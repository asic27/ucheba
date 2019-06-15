/** @file
 * @author Асаян А.В.
 * @version 1.0
 * @date 28.05.2019
 * @copyright ИБСТ ПГУ
 * @warning Работа студента.
 * @brief Заголовочный файл для модуля modAlphaCipher
 */
#pragma once
#include <vector>
#include <codecvt>
#include <string>
#include <map>
class modAlphaCipher
{
private:
    std::wstring numAlpha =
        L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";///< Русский алфавит по порядку.
    std::map <wchar_t,int> alphaNum;///< Ассоциативный массив "номер по символу"
    std::vector <int> key;///< Ключ
    /**
     * @brief Валидация ключа.
     * @param [in] s Ключ
     * @return Обработанный ключ.
     */
    std::wstring getValidKey(const std::wstring & s);
    /**
     * @brief Валидация открытого текста.
     * @param [in] s Открытый текст.
     * @return Обработыннй открытый тест.
     */
    std::wstring getValidOpenText(const std::wstring & s);
    /**
     * @brief Валидация текста, требующего расшифровки.
     * @param [in] s Текст, требующий расшифровки.
     * @return Шифр-текст.
     */
    std::wstring getValidCipherText(const std::wstring & s);
    /**
     * @brief Преобразование "строка-вектор"
     * @param [in] s Строка, требущая конвертации в целочисленный вектор.
     * @return Целочисленный вектор.
     */
    std::vector<int> convert(const std::wstring& s);
    /**
     * @brief Преобразование "вектор-строка.
     * @param [in] v Вектор, требующий преобразования в строку.
     * @return Строка.
     */
    std::string convert(const std::vector<int>& v);
public:
    /**
     *@brief Пустой конструктор для установки ключа.
     *@detail Конструктор запрещён.
     */
    modAlphaCipher()=delete;
    /**
     *@brief Конструктор для установки ключа.
     *@details Устанавливает ключ, с помощью которого будет осуществляться шифрование и расшифрование.
     *@param [in] skey Строка-ключ. Должна состоять из букв русского алфавита в верхнем регистре. Не должна быть пустой. Все символы в нижнем регистре будут автоматически преобразованы в верхний.
     *@throw cipher_error, если строка пустая или содержит символы не русского алфавита или ключ вырожденный.
     */
    modAlphaCipher(const std::wstring& skey);
    /**
     *@brief Метод шифрования текста шифром Гронсфельда. 
     *@param [in] open_text Открытый текст.Не должен быть пустой строкой. Должен содержать только символы русского алфавита. Строчные символы автоматически преобразуются к прописным. Все не-буквы удаляются 
     *@throw cipher_error, если строка пустая.
     */
    std::string encrypt(const std::wstring& open_text);
    /**
     *@brief Метод шифрования текста шифром Гронсфельда. 
     *@param [in] open_text Текст, требующий расшифровки.Не должен быть пустой строкой. Должен содержать только символы русского алфавита в верхнем регистре.
     *@throw cipher_error, если строка пустая, содержит символы не русского алфавита или символы в нижнем регистре.
     */
    std::string decrypt(const std::wstring& cipher_text);
};
class cipher_error: public std::invalid_argument
{
public:
    explicit cipher_error (const std::string& what_arg):
        std::invalid_argument(what_arg) {}
    explicit cipher_error (const char* what_arg):
        std::invalid_argument(what_arg) {}
};
