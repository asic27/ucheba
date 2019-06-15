#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <random>
#include <chrono>
using namespace std;
struct Cards {
    int suit;
    int value;
    Cards(int w,int h) {
        suit=w;
        value=h;
    }
    friend ostream& operator<< (ostream &out, const Cards &b) {
        out << "SUIT " << b.suit << ", VALUE " << b.value;
    }
    friend bool operator== (const Cards &a, const Cards &b) {
        return (a.suit == b.suit and a.value== b.value);
    }
};
int main(int argc, char **argv)
{
    enum suit {peaks=0,clubs=1,hearts=2,diamond=3};
    enum value {six,seven,eight,nine,ten,jack,queen,king,ACE};
    Cards y(0,0);
    vector <Cards> deck;
    for(int k=0; k<4; k++) {
        for(int i=0; i<9; i++) {
            Cards y(k,i);
            deck.push_back(y);
        }
    }

    shuffle(deck.begin(),deck.end(),mt19937(time(NULL)));
    for(int i=0; i<36; i++)
        cout<<deck[i]<<endl;
    for(int i=0; i<36; i++) {
        if((deck[i].suit==diamond or deck[i].suit==hearts) and (deck[i+1].suit==hearts or deck[i+1].suit==diamond)) {
            cout<<"Пара карт красной масти в позициях "<<i+1<<", "<<i+2<<endl;
            cout<<deck[i]<<" "<<deck[i+1]<<endl;
        }
    }
    for(int i=0; i<36; i++) {
        if(deck[i].value==deck[i+1].value) {
            cout<<"Пара карт с одинаковыми значениями в позициях "<<i+1<<", "<<i+2<<endl;
            cout<<deck[i]<<" "<<deck[i+1]<<endl;
        }
    }
    Cards q(clubs,queen);
    auto it1=find(deck.begin(),deck.end(),q);
    auto index = distance(deck.begin(), it1);
    cout<<"Пиковая дамма в колоде на "<<index+1<<" позиция"<<endl;
    for(int i=0; i<36; i++) {
        if(deck[i].value==ACE) {
            cout<<"Туз ";
            cout<<deck[i]<<". Позиция в колоде "<<i+1<<endl;
        }
    }
    return 0;
}
