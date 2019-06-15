
#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
using namespace std;
int main(int argc, char **argv)
{
    locale loc("ru_RU.UTF-8");
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
    string str="В караване было  верблюдов";
    wstring ws = codec.from_bytes(str);
    int x;
    cout<<"Введите целое число от 0 до 100 ---> ";
    cin>>x;
    if(x>=0 and x<=100) {
        if(x%10==1 and (x>=21 or x==1)) {

            ws.erase(24,2);
            ws.insert(16,to_wstring(x));
            ws.erase(14,1);

        }
        if(x%10>1 and x%10<5 and x>=21) {
            ws.erase(24,2);
            ws.insert(16,to_wstring(x));
            string s="а";
            wstring wt=codec.from_bytes(s);
            ws=ws+wt;

        }
        if(x%10==0 or x%10>=5) {
            ws.insert(16,to_wstring(x));
        }
        str = codec.to_bytes(ws);
        cout<<str<<endl;
    }
    return 0;
}
