#include <stdio.h>
#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
    int x=1,s=0;
    while(x!=0) {
        cout<< "Введите число последовательости"<<endl;
        cin>>x;
        if(x>0)
            s=s+x;
    }
    cout<<s<<endl;

    return 0;
}
