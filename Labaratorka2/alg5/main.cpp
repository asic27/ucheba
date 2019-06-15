#include <stdio.h>
#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
    {
        int i=1,a=0;
        int x;
        do {
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
            if(a==2) {
                cout<<"Простое"<<endl;
            }
            i=1;
            a=0;
        } while(x!=0);
    }
    return 0;
}
