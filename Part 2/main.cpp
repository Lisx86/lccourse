#include <iostream>
using namespace std;

enum class Fur{Alb=0,Negru=1,Mixt=2};

struct Dog
{
    string breed;
    int age;
    Fur bl;
};

void Print(Dog ZDogs[],int n)
{
    for(int i=0;i<=n-1;i++)
    {
        cout<<"Dog"<<" "<<i<<" "<<ZDogs[i].breed<<" "<<ZDogs[i].age<<endl;
    }
    cout<<endl;
}

void Sort(Dog ZDogs[],int n)
{
    for(int i=0;i<=n-1;i++)
    {
        if(ZDogs[i-1].age>ZDogs[i].age)
        {
            Dog Temp;
            Temp=ZDogs[i];
            ZDogs[i]=ZDogs[i-1];
            ZDogs[i-1]=Temp;
            i=1;
        }
    }
}

int main(){
    int n,x;
    cout<<"Please insert the number of Dogs"<<endl;
    cin>>n;
    Dog * Dogs = new Dog[n]; 
    for(int j=0;j<=n-1;j++)
    {
        cout<<"Dog nr "<<j+1<<" Breed =";
        cin>>Dogs[j].breed;
        cout<<"Dog nr "<<j+1<<" Age =";
        cin>>Dogs[j].age;
        cout<<"Dog nr "<<j+1<<" Fur =";
        cin>>x;
        switch(x)
        {
            case 0: {Dogs[j].bl=Fur::Alb;break;}
            case 1: {Dogs[j].bl=Fur::Negru;break;}
            case 2: {Dogs[j].bl=Fur::Mixt;break;}
            default: {Dogs[j].bl=Fur::Mixt;}
        }
    }
    Print(Dogs,n);
    Sort(Dogs,n);
    Print(Dogs,n);
    delete[] Dogs;
}
