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
    friend ostream& operator<<(ostream& o, const String & s);
    friend istream& operator>>(istream& o, String & s);
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
    int i=0;
    len=0;
    while(s[i]!='\0') {
        len++;
        i++;
    }
    value = new char[len];
    for(int i=0; i<len; i++) {
        value[i]=s[i];

    }

}
istream& operator>>(istream& inputStream,  String & s)
{
    int dl=0;
    char temp[90];
    inputStream >> s.value;
    for(int i=0; s.value[i]!=0; i++) {
        temp[i]=s.value[i];
        dl=dl+1;
    }
    delete[] s.value;
    s.len=dl;
    s.value=new char[s.len+1];
    for(int i=0; i<s.len; i++) {
        s.value[i]=temp[i];
    }
    s.value[s.len]=0;
}

int main(int argc, char **argv)
{
    
    String s;
    cin>>s;
    String s1("hello");
    String s2(s1);
    cout<<s2<<" "<<s1<<" "<<s<<endl;
    return 0;
}

