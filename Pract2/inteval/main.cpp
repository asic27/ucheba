#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;
using namespace std::chrono;
int RandomGenerator()
{
    static mt19937 rnd((uint64_t)&rnd);
    uniform_int_distribution<int> d(-1000000000,1000000000);
    return d(rnd);
}
int main(int argc, char **argv)
{
    int rd;
    vector <int> first;
    steady_clock::time_point tp1f = steady_clock::now();
    for(int i=0; i<10000000; i++) {
        rd=RandomGenerator();
        first.push_back(rd);
    }
    steady_clock::time_point tp2f = steady_clock::now();
    duration<double> d1 = tp2f-tp1f;
    cout<<d1.count()<<endl;
    vector <int> second(10000000);
    steady_clock::time_point tp1s = steady_clock::now();
    generate(second.begin(),second.end(),RandomGenerator);
    steady_clock::time_point tp2s = steady_clock::now();
    duration<double> d2 = tp2s-tp1s;
    cout<<d2.count()<<endl;
    steady_clock::time_point tp1t = steady_clock::now();
    vector <int> third(second);
    steady_clock::time_point tp2t = steady_clock::now();
    duration<double> d3 = tp2t-tp1t;
    cout<<d3.count()<<endl;
    return 0;
}
