#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int main(int argc, char **argv)
{
    double e=0;
    int c=0;
    ifstream f("data_v5.bin",ios::binary);
    ofstream ff("data_v5mod.bin",ios::binary);
    if(!f.is_open()) {
        cerr << "Error: file is not open\n";
        return 1;
    }
    while(f.read((char*)&e,sizeof(double))) {
        c++;
    }
    f.clear();
    f.seekg(ios::beg);
    cout<<c<<endl;
    double var[c];
    for(int i=0;i<c;i++){
        f.read((char*)&var[i],sizeof(double));
    }
    f.close();
    float rev[c];
    for(int i=0;i<c;i++){
    rev[i]=1/var[i];
    ff.write((char*)&rev[i],sizeof(float));
    }
    ff.close();
    return 0;
}
