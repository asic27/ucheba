#include <iostream>
using namespace std;
//char proverka(char *m, const int k)
//{
//   int i=0;
//   while(m[i]!='\0') {
//      if (m[i]<'A' or m[i]>'Z') {
//       return 'E';
//    }
// i++;
//  }
// if(k>i/2)
//     return 'E';
//   return 'S';
//}
char * rashifr(char *m,  int k)
{
    int sim=0;
    for (int i=0; m[i]!='\0'; i++) {
        sim=sim + 1;
    }
    int strok=(sim-1)/k + 1;
    int d=k*strok-sim;
    cout<<strok<<endl;
    char **masiv1= new char* [strok];
    for (int i = 0; i < strok; i++) {
        masiv1[i] = new char [k];
    }
    int p=0;
    int t=0;
    for (int j=0; j<k; j++) {
        p=j*strok;
        for (int i=0; i<strok; i++) {
          
           if(i+1==strok and j>k-1-d){
                
                 masiv1[i][j]='*';
                 t++;
                 
           }
            else 
                masiv1[i][j]=m[p+i-t];
        }
    }

    for (int i=0; i<strok; i++) {
        for (int j=0; j<k; j++)
            cout<<masiv1[i][j];

    }
    cout<<endl;
    for (int i = 0; i<strok; i++)
        delete[] masiv1[i];
    delete[] masiv1;

}
int main()
{
    int key;
    cout<<"Введите ключ "<<endl;
    cin>>key;
    //char text[]="OOOSPARTAA";
    char ztext[]="PERRTIIAAVN*";
    //if (proverka(text,key)=='E') {
    //  return 1;
    //}
    // if (proverka(ztext,key)=='E') {
    //    return 1;
    // }
    //shifr(text,key);
    rashifr(ztext,key);
    return 0;
}
