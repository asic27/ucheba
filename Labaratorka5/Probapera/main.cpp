#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int main(int argc, char **argv)
{
    struct demo {
        char ID[5];
        double x;
        int num;
        short int shrt;
    };
    demo var= {"DEMO", 5.25, -1, 128};
    ofstream f("demo.bin", ios::out | ios::binary);
    f.write((char*)&var, sizeof var);
}
