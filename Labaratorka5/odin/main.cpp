#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int main(int argc, char **argv)
{
	ifstream fit("posled.txt");//,ios::out | ios::binary);
    //string b;
    int c[10];
    if(!fit.is_open()){
        cerr << "Error: file is not open\n";
        return 1;
    }
    for(int i=0;i<10;i++)
    fit>>c[i];
    for(int i=0;i<10;i++){
        cout<<setw(10)<<oct<<c[i]<<setw(10)<<dec<<c[i]<<setw(10)<<hex<<c[i]<<endl;
        
    }
    fit.close();
	return 0;
}
