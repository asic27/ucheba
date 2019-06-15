#include <iostream>
#include <string>
using namespace std;
int main(int argc, char **argv)
{
    string str="deb http://mirror.mephi.ru/debian/ stretch main contrib non-free\ndeb-src http://mirror.mephi.ru/debian/ stretch main contrib non-free\ndeb http://security.debian.org/ stretch/updates main contrib non-free\ndeb-src http://security.debian.org/ stretch/updates main contrib non-free\ndeb http://mirror.mephi.ru/debian/ stretch-updates main contrib non-free\ndeb-src http://mirror.mephi.ru/debian/ stretch-updates main contrib non-free\ndeb http://mirror.mephi.ru/debian stretch-backports main contrib non-free\ndeb-src http://mirror.mephi.ru/debian stretch-backports main contrib non-free\n";
    int s=0;
    do {
        s = str.find("mephi");
        if (s!=-1) {
            str=str.replace(s,5,"yandex");
        }
    } while(s!=-1);
    cout<<str;
    return 0;
}
