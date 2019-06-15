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
class Rectangle
{ 
public:
    double width;
    double height;
    Rectangle(){
        width=0;
        height=0;
    };
    Rectangle(double w,double h) {
        width=w;
        height=h;
    };
   friend bool operator >(Rectangle a,Rectangle b)
    {
        if(a.width*a.height>b.width*b.height)
            return true;
        else
            return false;
    }
    friend bool operator <(Rectangle a,Rectangle b)
    {
        if(a.width*a.height<b.width*b.height)
            return true;
        else
            return false;
    }
   Rectangle &operator =(Rectangle & b)
    {
        width=b.width;
        height=b.height;
        return *this;
    }
    friend ostream& operator<< (ostream &out, const Rectangle &b){
         out << "WIDTH " << b.width << ", HEIGHT " << b.height;
        }
};
int main(int argc, char **argv)
{
    Rectangle a(20,20);
    Rectangle b(4,5);
    Rectangle c(9,2);
    Rectangle p[3]{a,b,c};
    sort(p,3);
    for(int i=0;i<3;i++)
        cout<<p[i]<<endl;
    return 0;
}
