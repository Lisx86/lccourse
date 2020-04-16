#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int n;
    cout<<"Va rog introduceti numarul de numere in masiv"<<endl;
    cin>>n;
    
    // array sizes must be known at compile time
    // please declare n as 'constexpr int n = <maximum size>;' and use another variable to specify how many items youare working with
    int submas[n],mas[n];
    for(int i=1;i<=n;i++)
    {
        cout<<"Introduceti nr pentru masivul ["<<i<<"]=";
        cin>>mas[i];
    }
    int rezultat=mas[1];
    for(int i=1;i<n;i++)
    {
        if(abs(mas[i])<abs(rezultat))
        {
            submas[1]=mas[i];
            rezultat=mas[i];
        }
        if(mas[i]==0)
        {
            submas[1]=mas[i];
            rezultat=0;
            cout<<"submas = {"<<submas[1]<<"}"<<endl;
            cout<<"rezultat = "<<rezultat;
            return 0;
        }
    }
        
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(abs(mas[i]+mas[j])<abs(rezultat))
            {
                rezultat = mas[i]+mas[j];
                submas[1] = mas[i];
                submas[2] = mas[j];
            }
        }
    }
    if(submas[2]==0)
    {
        cout<<"submas = {"<<submas[1]<<"}"<<endl;
        cout<<"rezultat = "<<rezultat;
    }
    else
    {
        cout<<"submas = {"<<submas[1]<<","<<submas[2]<<"}"<<endl;
        cout<<"rezultat = "<<rezultat;
    }
}
    

