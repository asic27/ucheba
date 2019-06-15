#include <iostream>
#include <string>
using namespace std;
class String
{
    char * value;
    int len;
public:
    String():value(new char[1] {}),len(0) {}; 
    String(const String& s);
    ~String();
    friend ostream& operator<<(ostream& o, const String & s);
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
int main(int argc, char **argv)
{   String s;
    String s1=s;
    cout<<s1;
    return 0;
}
