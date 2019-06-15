#include <iostream>
#include <locale>
#include "modAlphaCipher.h"
using namespace std;
// проверка, чтобы строка состояла только из прописных букв
bool isValid(const wstring& s)
{
    std::locale loc("ru_RU.UTF-8");
    for(auto c:s)
        if (!iswalpha(c) || !iswupper(c))
            return false;
    return true;
}
int main(int argc, char **argv)
{
    std::locale loc("ru_RU.UTF-8");
    std::locale::global(loc);
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec;
    wstring key;
    wstring text;
    unsigned op;
    wcout<<L"Cipher ready. Input key: ";
    wcin>>key;
    wcout<<L"Key loaded\n";
    try {
    modAlphaCipher cipher(key);
        do {
            wcout<<L"Cipher ready. Input operation (0-exit, 1-encrypt, 2-decrypt): ";
            wcin>>op;
            if (op > 2) {
                wcout<<L"Illegal operation\n";
            } else if (op >0) {
                wcout<<L"Cipher ready. Input text: ";
                wcin>>text;
                if (op==1) {
                    wcout<<"Encrypted text: "<<codec.from_bytes(cipher.encrypt(text))<<endl;
                } else {
                    wcout<<"Decrypted text: "<<codec.from_bytes(cipher.decrypt(text))<<endl;
                }
            }

        } while (op!=0);
    } catch (const cipher_error & e) {
        cerr<<"Error: "<<e.what()<<endl;
    }
    return 0;
}
