#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <sstream>
using namespace std;
struct Data {
    string FirstName;
    string LastName;
    string Patronymic;
    //vector<int> Evaluations;
    friend bool operator< (const Data &d1, const Data &d2) {
        if(d1.FirstName != d2.FirstName) {
            return d1.FirstName < d2.FirstName;
        } else {
            if(d1.LastName != d2.LastName) {
                return d1.LastName < d2.LastName;
            } else {
                if(d1.Patronymic != d2.Patronymic) {
                    return d1.Patronymic < d2.Patronymic;
                }
            }

        }
    }
    friend ostream& operator<< (ostream &out, const Data &data) {
        cout<<data.FirstName<<" "<<data.LastName<<" "<<data.Patronymic<<endl;
    }
};
int main()
{
    ifstream Read("name.txt");
    if (!Read) {
        cout << "Cannot open file" << endl;
        return 1;
    }
    int str=0;
    string line;
    while(getline(Read, line)) {
        stringstream lineStream(line);
        while(getline(lineStream, line, ' ')) {
            ++str;
        }
    }
    str=str/3;
    vector<Data> slova;
    Read.clear();
    Read.seekg(ios::beg);
    Data data;
    for(int i=0; i<str; i++) {
        Read >> data.FirstName;
        Read >> data.LastName;
        Read >> data.Patronymic;
        slova.push_back(data);
    }
    cout<<"До сортировки: "<<endl;
    for(int i=0; i<str; i++) {
        cout<<slova[i];

    }
    sort(slova.begin(),slova.end());
    cout<<"После сортировки: "<<endl;
    for(int i=0; i<str; i++) {
        cout<<slova[i];

    }
    int t;
    for(int i=0; i<str; i++) {
        if(slova[i].FirstName==slova[i+1].FirstName) {
            cout<<"Однофамильцы: "<<endl;
            t=i;
            string fn=slova[i].FirstName;
            while(slova[t].FirstName==fn) {

                cout<<slova[t];
                t++;
            }
            i=t-1;
        }
    }
    map<string, int> ounter;
    map<string, int>::iterator it;
    for(int i=0; i<str; i++) {
        ounter[slova[i].LastName]++;
    }
    auto x = std::max_element(ounter.begin(), ounter.end(), [](const pair< string, int>& p1, const pair<string, int>& p2) {
        return p1.second < p2.second;
    });
    auto y = std::min_element(ounter.begin(), ounter.end(), [](const pair< string, int>& p1, const pair<string, int>& p2) {
        return p1.second < p2.second;
    });
    cout<<"Most popular: "<<endl;
    for(it=ounter.begin();it!=ounter.end();it++){
        if(it->second==x->second)
            cout<<it->first<<endl;
    }
    cout<<"Most rare: "<<endl;
    for(it=ounter.begin();it!=ounter.end();it++){
        if(it->second==y->second)
            cout<<it->first<<endl;
    }
    Read.close();
}
