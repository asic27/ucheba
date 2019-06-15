#include <iostream>
using namespace std;
template <typename T> void sort (T* arr, int len){
  T tmp;
  for(int i = 0;i<len;i++){
    for(int j = (len-1);j>=(i+1);j--){
      if(arr[j]<arr[j-1]){
        tmp = arr[j];
        arr[j]=arr[j-1];
        arr[j-1]=tmp;
      }
    }
  }
}
int main(int argc, char **argv)
{    
	int I[5]{5,4,6,9,11};
    double D[5]{3.2,3.4,4.5,0.0,99.1};
    char C[5]{'b','v','e','k','c'};
    sort(I,5);
    sort(D,5);
    sort(C,5);
    for(int i=0;i<5;i++){
        cout<<I[i]<<" ";
    }
        cout<<endl;
    for(int i=0;i<5;i++){
        cout<<D[i]<<" ";
    }
        cout<<endl;
    for(int i=0;i<5;i++){
        cout<<C[i]<<" ";
    }
        cout<<endl;
    return 0;
        
}