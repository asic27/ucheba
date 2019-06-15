#include <stdio.h>
#include <iostream>
using namespace std;
double *normmass(double *mas, int raz);
double *normmass(double *mas, int raz)
{   
    double max=0, min=0;
    double*p = new double[raz];
    
    if(mas[0]>=0) {
        for (int i = 0; i <= raz-1; i++) {
            if (mas[i]>=max)
                max=mas[i];
        }
    } else {
        max=mas[0];
        for (int i = 0; i <= raz-1; i++) {
            if (mas[i]>=max)
                max=mas[i];
        }
    }
    min=max;
    for (int i = 0; i <= raz-1; i++) {
        if(mas[i]<min)
            min=mas[i];
    }
    cout<<"Максимальное значение массива "<<max<<endl;
    cout<<"Минимальное значение массива "<<min<<endl<<endl;
    for (int i = 0; i <= raz-1; i++) {
        p[i]= (mas[i]-min)/(max-min);
    }
    return p;
}
	int main(){ 
    int a;
    cout<<"Введите размер массива"<<endl;
    cin >>a;
    cout<<endl;
    double * sas = new double[a];
    
    for (int i = 0; i <= a-1; i++) {
        cout<<"Введите элемент массива"<<endl;
        cin>>sas[i];
        cout<<endl;
    }
    double * nm = normmass(sas, a);
    
    cout<<"Элементы исходного массива"<<endl;
    for (int i = 0; i <= a-1; i++){
        cout<<sas[i]<<endl<<endl;
        
    }
    cout<<"Элементы нового массива"<<endl;
    for (int i=0;i <= a-1; i++){
        cout<<nm[i]<<endl<<endl;
    }
    delete[] nm;
    delete[] sas;
    return 0;
}
  

