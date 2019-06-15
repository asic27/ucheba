#include <iostream>
#include <algorithm>
#include <crypt.h>
#include <string>
#include <fstream>
#include <thread>
#include <chrono>
#include <mutex>
#include <atomic>
using namespace std;
void findPass(string pass, const string& hash)
{
    crypt_data *pCryptData = new crypt_data;
    size_t pos = hash.find_last_of('$');
    string hashHead = hash.substr(0,pos);
    do {
        string newHash(crypt_r(pass.data(),hashHead.data(),pCryptData));
        if (newHash == hash) {
            static mutex mtx;
            {
                lock_guard<mutex> lock(mtx);
                cout<<"Hash: "<<hash<<endl<<"Pass: "<<pass<<endl;
                break;
            }
        }
    } while ( next_permutation( pass.begin(), pass.end() ) );
    delete pCryptData;
}
int main(int argc, char **argv)
{
    ifstream Read("/home/asic27/Labaratorka7/tree/Release/hash.txt");
    string pass1="123456789";
    string pass2="231456789";
    string pass3="561234789";
    string x;
    string y;
    thread th_1;
    thread th_2;
        Read>>x;
        th_2=thread(findPass,pass2,x);
        if(th_2.joinable())
            th_2.join();
        if(th_1.joinable())
            th_1.join();
        
    return 0;
}
