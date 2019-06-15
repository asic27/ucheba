#include <iostream>
using namespace std; 
int LFSR_Galois (void)
{
    // for polynomial 0x80000057, reversed 0xea000001
    static unsigned long S = 0x000000000F000001;
    if (S & 1) {
        S = ((S ^ 0xF000000000000000) >> 1) | 0x8000000000000000;
        cout<< hex <<S<<endl;
        return 1;}
    else {
        S >>= 1;
        return 0;}
}
int main()
{   
    cout<<LFSR_Galois()<<endl;
    return 0;
}