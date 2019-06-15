#include <iostream>
#include <string>
using namespace std;
template <typename T1, typename T2> class DoubleBox
{
private:
    T1 a = T1();
    T2 b = T2();
    // инициализация атрибута при объявлении, стандарт C++11
public:
    DoubleBox() {}
    DoubleBox(const T1 value1, const T2 value2):a(value1),b(value2) {}
    void getContent(const T1 value1,const T2 value2);
    void setContent(const T1 value1, const T2 value2);
};
template <typename T1, typename T2> void DoubleBox<T1,T2>::getContent(T1 value1,T2 value2) 
{   
    value1=a;
    value2=b;
    cout<<value1<<" "<<value2<<endl;
}
template <typename T1, typename T2> void DoubleBox<T1,T2>::setContent( const T1 value1,const T2 value2)
{
    a = value1;
    b = value2;
}
int main(int argc, char **argv)
{  
    int b=0;
    char p='a';
    float x=0.0;
    string t;
    DoubleBox <int,char> y;
    DoubleBox <float,string> v;
    v.setContent(3.2,"Check");
    y.setContent(7,'I');
    y.getContent(b,p);
    v.getContent(x,t);
    return 0;
}
