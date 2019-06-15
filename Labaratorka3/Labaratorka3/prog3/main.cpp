#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char **argv)
{
    int z;
    string str="deb http://mirror.mephi.ru/debian/ stretch main contrib non-free\ndeb-src http://mirror.mephi.ru/debian/ stretch main contrib non-free\ndeb http://security.debian.org/ stretch/updates main contrib non-free\ndeb-src http://security.debian.org/ stretch/updates main contrib non-free\ndeb http://mirror.mephi.ru/debian/ stretch-updates main contrib non-free\ndeb-src http://mirror.mephi.ru/debian/ stretch-updates main contrib non-free\ndeb http://mirror.mephi.ru/debian stretch-backports main contrib non-free\ndeb-src http://mirror.mephi.ru/debian stretch-backports main contrib non-free\n";
    z=str.size();
    cout<<"Количество символов: ";
    cout<<z<<endl;
    int k=0;
    for(int i=0; i<z; i++) {

        if(str[i]!=' ' and str[i]!='\n'){
            k++;
        }
    }
    cout<<"Количество символов без пробелов и символов конца строки: ";
    cout<<k<<endl;

    return 0;
}
