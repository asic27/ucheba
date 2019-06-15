int main(int argc, char **argv)
{
    double max=0, min=0;
    int raz;
    cout<<"Введите размер массива"<<endl;
    cin >> raz;
    double * mas = new double[raz];
    for (int i = 0; i <= raz-1; i++) {
        cout<<"Введите элемент массива"<<endl;
        cin>>mas[i];
    }
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
    cout<<max<<endl;
    cout<<min<<endl;
    for (int i = 0; i <= raz-1; i++) {
        mas[i]= (mas[i]-min)/(max-min);
        cout<<mas[i]<<endl;
    }
    delete[] mas;
    return 0;
}
