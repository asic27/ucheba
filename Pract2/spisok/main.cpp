#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <random>
#include <fstream>
using namespace std;
struct Peoples{
    
    string family;
    string name;
    string mname;
    Peoples(string w,string h,string c) {
        family=w;
        name=h;
        mname=c;
    }
    //vector <string> sv;
    friend ostream& operator<< (ostream &out, const Peoples &b) {
        out << " фамилия " << b.family << " имя " << b.name <<" отчество "<<b.mname<<endl;
    }
    friend istream& operator>>(istream& stream, Peoples& line)
    {
        return getline(stream, line.family);
    }
};
int main(int argc, char **argv)
{   string str="Иваныч";
    string st="Петр";
    string stt="Лов";
    Peoples y(str,st,stt);
    cout<<y<<endl;
	ifstream list("name.txt");
    vector <Peoples> nlist;
	return 0;
}
