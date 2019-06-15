#include <iostream>
#include <string>
using namespace std;
class String
{
    char * value;
    int len;
public:
    String():value(new char[1] {}),len(0) {}; // конструктор по умолчанию
    String(const String& s);
// конструктор копирования
    String(const char * s);
// конструктор инициализации Си-строкой
    ~String();
    friend ostream& operator<<(ostream& outputStream, const String & s);
// деструктор
};

ostream& operator<<(ostream& outputStream, const String & s)
{
    return outputStream << s.value;
}
String::~String()
{
    delete[] value;
}
String::String(const String& s)
{
    len=s.len;
    value = new char[len+1];
    for (int i=0; i<=len; i++)
        value[i]=s.value[i];
}
String::String(const char *s)
{
    len=0;
    while(s[len]!='\0') {
        len++;
    }
    value = new char[len];
    for(int i=0; i<len; i++) {
        value[i]=s[i];

    }
    value[len]=0;
}
int main(int argc, char **argv)
{
    String s1("hello");
    String s2(s1);
    cout<<s2<<" "<<s1<<" "<<endl;
    return 0;
}
