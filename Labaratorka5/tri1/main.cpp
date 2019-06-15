#include <iostream>
#include <fstream>
#include <vector> 
using namespace std;
int main(int argc, char **argv)
{
	ifstream fit("data_v5.txt");
    double number;
    int size=0;
   vector<double> chisla; 
    if(!fit.is_open()){
        cerr << "Error: file is not open\n";
        return 1;
    }
    double sr=0;
    double sum=0;
    while(fit>>number)
        {
            chisla.push_back(number);
            size++;
        }
         
   for(int i=0;i<chisla.size();i++){
        sum=sum+chisla[i];
}
    sr=sum/size;
    cout<<sr<<endl;
    fit.close();
	return 0;
}
