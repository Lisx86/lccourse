#include <iostream>
#include <fstream>
using namespace std;

int n;

enum class Fur{Alb=0,Negru=1,Mixt=2};

struct Dog
{
    string breed;
    int age;
    Fur bl;
};

int Count_Lines(string path)
{
    ifstream f(path);
    string line;
    while(!f.eof())
    {
        getline(f,line);
        n++;
    }
    f.close();
    n=n-1;
    cout<<n;
    return n;
}

void Load(Dog ZDogs[],string path)
{
    ifstream f(path);
    int i=0;
    for(int i=0;i<=n-1;i++)
    {
        f>>ZDogs[i].breed;
        f>>ZDogs[i].age;
    }
    f.close();
}

void AddDog(Dog ZDogs[],string path)
{
    fstream f(path);
    cout<<"Please insert new dogs breed:";
    cin>>ZDogs[n-1].breed;
    cout<<"Please inset new dogs age:";
    cin>>ZDogs[n-1].age;
    for(int i=0;i<=n-1;i++)
    {
        f<<ZDogs[i].breed<<" ";
        f<<ZDogs[i].age;
        f<<endl;
        if(ZDogs[i].breed==ZDogs[n-1].breed)break;
    }
    f.close();
}

void Print(Dog ZDogs[],int n)
{
    for(int i=0;i<=n-1;i++)
    {
        cout<<"Dog "<<i<<" "<<ZDogs[i].breed<<" "<<ZDogs[i].age<<endl;
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
    int raspuns;
    n=Count_Lines("file.txt");
    Dog * Dogs = new Dog[n];
    Load(Dogs,"file.txt");
    while(true)
    {
        cout<<"1)Add a line"<<endl;
        cout<<"2)Remove a line"<<endl;
        cout<<"3)Print Original List"<<endl;
        cout<<"4)Sort and Print List by age"<<endl;
        cout<<"5)Exit"<<endl;
        cout<<"Your Choice:";
        cin>>raspuns;
        cout<<endl;
        switch(raspuns)
        {
        case 1:
        {
            delete[] Dogs;
            n++;
            Dog * Dogs = new Dog[n];
            Load(Dogs,"file.txt");
            AddDog(Dogs,"file.txt");
        }
        case 2:{}
        case 3:{Print(Dogs,n);break;}
        case 4:{}
        }
        if(raspuns==5) break;
    }
    delete[] Dogs;
}
