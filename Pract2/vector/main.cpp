#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;
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
    vector <int> second(10000000);
    for(int i=0;i<10000000;i++){
        rd=RandomGenerator();
        first.push_back(rd);
    }
    generate(second.begin(),second.end(),RandomGenerator);
    vector <int> third(second);
	return 0;
}
