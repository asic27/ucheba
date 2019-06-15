#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
using namespace std;

//Гост 19.701-90(алгоритмы)
wchar_t encryptSimvola(wchar_t x, const int key)
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
    wstring m= L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    for(int k=0; k<33; k++) {
        if(x==m[k]) {
            if(k+key<33) {
                x=m[k+key];
                return x;

            } else {
                x=m[k+key-33];
                return x;

            }

        }

    }
    return x;
}
wchar_t decryptSimvola(wchar_t x, const int key)
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
    wstring m= L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    for(int k=0; k<33; k++) {
        if(x==m[k]) {
            if(k-key>=0) {
                x=m[k-key];
                return x;

            } else {
                x=m[33+k-key];
                return x;

            }

        }

    }
    return x;
}

wstring encrypt(const wstring & text, const int key)
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
    wchar_t x=0;
    wstring ntext;
    int z=text.size();
    for(int i=0; i<z; i++) {
        if((text[i]<L'А' or text[i]>L'Я') and text[i]!=L'Ё' )
            if ((text[i]<L'а' or text[i]>L'я') and text[i]!=L'ё') {
                continue;
            }
        x=text[i];
        x=toupper(x,loc);
        x=encryptSimvola(x,key);
        ntext=ntext + x;


    }



    return ntext;
}
wstring decrypt(const wstring & text, const int key)
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
    wchar_t x=0;
    wstring ntext;
    int z=text.size();
    for(int i=0; i<z; i++) {
        if((text[i]<L'А' or text[i]>L'Я') and text[i]!=L'Ё' )
            if ((text[i]<L'а' or text[i]>L'я') and text[i]!=L'ё' ) {
                ntext=L"ОШИБКА!";
                break;
                
            }
        x=text[i];
        x=toupper(x,loc);
        x=decryptSimvola(x,key);
        ntext=ntext + x;


    }



    return ntext;
}

int main(int argc, char **argv)
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    int key;
    wchar_t answ;
tryAgain:
    wcout<<L"D/E?"<<endl;
    wcin>>answ;
    if(answ=='E') {
        wcout<<L"Введите ключ - ";
        wcin>>key;
        wcout<<L"Введите строку для зашифровки - "<<endl;
        wstring text;
        wcin>>text;
        text=encrypt(text,key);
        wcout<<L"Результат шифрования: ";
        wcout<<text<<endl;
    } else {
        if(answ=='D') {
            wcout<<L"Введите ключ - ";
            wcin>>key;
            wcout<<L"Введите строку для расшифровки - "<<endl;
            wstring text;
            wcin>>text;
            text=decrypt(text,key);
            wcout<<L"Результат расшифровки: ";
            wcout<<text<<endl;

        } else {
            wcout<<L"Неверно"<<endl;
            goto tryAgain;
        }
    }
        return 0;
    }
