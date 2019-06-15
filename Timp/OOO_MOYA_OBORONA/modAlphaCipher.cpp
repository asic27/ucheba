#include "modAlphaCipher.h"
#include <iostream>
#include <locale>
#include <cctype>
modAlphaCipher::modAlphaCipher(const std::wstring& skey)
{
    for (unsigned i=0; i<numAlpha.size(); i++) {
        alphaNum[numAlpha[i]]=i;
    }
    key = convert(getValidKey(skey));
    int n = 0;
    for (auto e:key) {
        if (e==0)
            n++;
    }
    if (2*n > key.size())
        throw cipher_error("WeakKey");
}
std::string modAlphaCipher::encrypt(const std::wstring& open_text)
{
    std::vector<int> work = convert(getValidOpenText(open_text));
    for(unsigned i=0; i < work.size(); i++) {
        work[i] = (work[i] + key[i % key.size()]) % alphaNum.size();
    }
    return convert(work);
}
std::string modAlphaCipher::decrypt(const std::wstring& cipher_text)
{
    std::vector<int> work = convert(getValidCipherText(cipher_text));
    for(unsigned i=0; i < work.size(); i++) {
        work[i] = (work[i] + alphaNum.size() - key[i % key.size()]) % alphaNum.size();
    }
    return convert(work);
}
inline std::vector<int> modAlphaCipher::convert(const std::wstring& s)
{
    std::vector<int> result;
    for(auto c:s) {
        result.push_back(alphaNum[c]);
    }
    return result;
}
inline std::string modAlphaCipher::convert(const std::vector<int>& v)
{
    std::locale loc("ru_RU.UTF-8");
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec;
    std::wstring result;
    std::string res;
    for(auto i:v) {
        result.push_back(numAlpha[i]);
    }
    res=codec.to_bytes(result);
    return res;
}
inline std::wstring modAlphaCipher::getValidKey(const std::wstring & s)
{
    std::locale loc("ru_RU.UTF-8");
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec;
    if (s.empty())
        throw cipher_error("Empty key");
    std::wstring tmp(s);
    for (auto & c:tmp) {
        if ((c<L'А' || c>L'я') and c!=L'Ё' and c!=1105) {
            std::string t;
            t = codec.to_bytes(s);
            throw cipher_error(std::string("Invalid key ")+t);
        }
        c = toupper(c,loc);
    }
    return tmp;
}
inline std::wstring modAlphaCipher::getValidOpenText(const std::wstring & s)
{
    std::locale loc("ru_RU.UTF-8");
    std::wstring tmp;
    for (auto c:s) {
        if ((c>=L'А' && c<=L'я') || c==L'Ё' || c==1105) {
            tmp.push_back(toupper(c,loc));
        }
    }
    if (tmp.empty())
        throw cipher_error("Empty open text");
    return tmp;
}
inline std::wstring modAlphaCipher::getValidCipherText(const std::wstring & s)
{
    std::locale loc("ru_RU.UTF-8");
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec;
    if (s.empty())
        throw cipher_error("Empty cipher text");
    for (auto c:s) {
        if ((c<L'А' || c>L'Я') and c!=L'Ё') {
            std::string t;
            t = codec.to_bytes(s);
            std::cout<<t;
            throw cipher_error(std::string("Invalid cipher text ")+t);
        }
    }
    return s;
}
