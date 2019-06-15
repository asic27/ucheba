#include <stdio.h>
#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
    int n,x;
    cout<< "Введите искомое число последлвательности"<<endl;
    cin >> n;
    if(n!=0) {
        while(x!=n) {
            cout<< "Введите число последовательости"<<endl;
            cin>>x;
            if(x==0) {
                cout<<"Не найдено"<< endl;
                break;
            }
            if (x==n)
                cout<<"Найдено "<< x<< endl;
        }
       
    }
    else
    cout<< "Число не должно быть равно нулю"<<endl;
    return 0;

}
