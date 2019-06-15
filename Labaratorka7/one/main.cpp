#include <iostream>
#include <algorithm>
#include <crypt.h>
#include <string>
#include <fstream>
using namespace std;
void findPass(string pass, const string& hash)
{
    crypt_data *pCryptData = new crypt_data;
    size_t pos = hash.find_last_of('$');
    string hashHead = hash.substr(0,pos);
    do {
        string newHash(crypt_r(pass.data(),hashHead.data(),pCryptData));
        if (newHash == hash) {
            cout<<"Hash: "<<hash<<endl<<"Pass: "<<pass<<endl;
            break;
        }
    } while ( next_permutation( pass.begin(), pass.end() ) );
    delete pCryptData;
}
int main(int argc, char **argv)
{
ifstream Read("/home/asic27/Labaratorka7/two/Debug/hash.txt");
    string pass="123456789";
    string x;
    while((Read>>x).good()) {
        findPass(pass,x);
    }
    return 0;
}
