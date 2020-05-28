#include <iostream>
#include <fstream>
using namespace std;

int n,k;

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
    cout<<n<<endl;
    n=n-1;
    cout<<n<<endl;
    return n;
}

void Load(Dog* ZDogs,string path)
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

Dog& AddDog(Dog*& ZDogs)
{
    if(k-n>0)
    {
        n++;
        cout<<"Please insert new dogs breed:";
        cin>>ZDogs[n-1].breed;
        cout<<"Please inset new dogs age:";
        cin>>ZDogs[n-1].age;
        return ZDogs[n-1];
    }
    else
    {
        k=k+10;
        Dog * Dogz = new Dog[k];
        for(int i=0;i<=n-1;i++)
        {
            Dogz[i]=ZDogs[i];
        }
        delete[] ZDogs;
        ZDogs = Dogz;
        return Dogz[n-1];
    }
}

void Save(Dog* ZDogs,string path){
    fstream f(path);
    for(int i=0;i<=n-1;i++)
    {
        f<<ZDogs[i].breed<<" ";
        f<<ZDogs[i].age<<endl;
    }
    f.close();
}

void Print(Dog* ZDogs){
    for (int i = 0; i <= n-1; i++)
    {
        cout<<i<<") "<<ZDogs[i].breed<<" "<<ZDogs[i].age<<endl;
    }
    
}

int main(){
    int raspuns;
    n=Count_Lines("file.txt");
    k=n+10;
    Dog * Dogs = new Dog[k];
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
            Print(Dogs);
            AddDog(Dogs);
            Print(Dogs);
            Save(Dogs,"file.txt");
        }
        case 2:{}
        case 3:{}
        case 4:{}
        }
        if(raspuns==5) break;
    }
    delete[] Dogs;
}


