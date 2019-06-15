#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
void tabl(int sischis)
{
    if(sischis==16) {
        for(int i=1; i<16; i++) {
            cout<<endl;
            for(int j=1; j<16; j++) {
                int z=i*j;
                cout<<setw(10)<<hex<<i<<'*'<<j<<'='<<z<<endl;
            }
        }
    }
    if(sischis==8) {
        for(int i=1; i<8; i++) {
            cout<<endl;
            for(int j=1; j<8; j++) {
                int z=i*j;
                cout<<setw(10)<<oct<<i<<'*'<<j<<'='<<z<<endl;
            }
        }
    }
    if(sischis==10) {
        for(int i=1; i<10; i++) {
            cout<<endl;
            for(int j=1; j<10; j++) {
                int z=i*j;
                cout<<setw(10)<<i<<'*'<<j<<'='<<z<<endl;
            }
        }
    }
}
int main(int argc, char **argv)
{
    int x;
    cin>>x;
    tabl(x);
    return 0;
}
