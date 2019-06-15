#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int i=1,a=0;
    int x;
    cout<<"Введите число для проверки "<< endl;
    cin>>x;
    while (i<=x) {
        if(x%i==0) {
            a=a+1;
            i++;
        } else {
            i++;
        }
        
    }
    if(a==2)
            cout<<"Да"<<endl;
            else
            cout<<"Нет"<<endl;
    return 0;
}
