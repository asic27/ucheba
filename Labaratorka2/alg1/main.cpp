#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, char **argv)
{
    int n,i=0;
    double x,sr,s=0;
    cout<< "Длина последовательности"<<endl;
    cin >> n;
    n=abs(n);
    while( i < n) {
        cout << "x равен"<<endl;
        cin >> x;
        s=s+x;
        i++;
    }
    sr=s/n;
    cout<<"Среднеарефметическое "<<n<<" чисел\n"<<sr<<endl;
    return 0;
}
