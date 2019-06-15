#include <iostream>
using namespace std;
template <typename T, int size> class Array
{
private:
    T MAS[size];
public:
    Array() {}
    Array(T a) {
        for(int i=0; i<size; i++)
            MAS[i]=a;
    }
    Array(T*m,int s) {
        for(int i=0; i<s; i++)
            MAS[i]=m[i];
    }
    T& operator [](const int inde);
    const T& operator [](const int inde) const;
};
template <typename T,int size>
T& Array<T,size>::operator [](const int inde)
{
    return MAS[inde];
}
template <typename T,int size>
const T& Array<T,size>::operator [](const int inde) const
{
    return MAS[inde];
}
int main(int argc, char **argv)
{
    int massiv[4] {1,4,8,7};
    Array<char,10> z;
    Array <int, 5> x(4);
    Array <int,5> y(massiv,4);
    y[4]=56;
    for(int i=0;i<5;i++){
    cout<<x[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<5;i++){
    cout<<y[i]<<" ";
    }
    cout<<endl;
    return 0;
}
