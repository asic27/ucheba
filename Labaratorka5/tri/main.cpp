#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int main(int argc, char **argv)
{
    fstream f("file2.txt",ios::in | ios::out);
    if(!f.is_open()) {
        cerr << "Error: file is not open\n";
        return 1;
    }
    f.seekp(0,ios::end);
    ifstream f1("file1.txt");
    if(!f1.is_open()) {
        cerr << "Error: file is not open\n";
        return 1;
    }
    f1.seekg(0,ios::end);
    int f1size = f1.tellg();
    //cout<<f1size;
    f1.seekg(0,ios::beg);
    char* buf = new char[f1size];
    f1.read(buf,f1size);
    f.write(buf,f1size);
    delete[]buf;
    return 0;
}
