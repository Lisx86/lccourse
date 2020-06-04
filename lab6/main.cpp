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
    struct Dog* next = nullptr;
};

Dog* Load(string path){
    Dog* first = new Dog();
    Dog* latest = first;
    fstream f(path);
    f>>first->breed;
    f>>first->age;

    while(f.eof()!=true)
    {
        Dog* last = new Dog();
        f>>last->breed;
        f>>last->age;
        latest->next = last;
        latest = last;
    }
    f.close();
    return first;
}

void Print(Dog* first){
    Dog* selected = first;
    while(selected->next!=nullptr)
    {
        cout<<selected->breed<<" "<<selected->age<<endl;
        selected = selected->next;
    }
}

Dog* AddDog(Dog* first,int index){
    int i=0;
    Dog* selected = first;
    if(index==1)
    {
        Dog* NewDog = new Dog();
        cout<<"insert breed:";
        cin>>NewDog->breed;
        cout<<"insert age:";
        cin>>NewDog->age;
        NewDog->next=first;
        first = NewDog;
    }
    else
    {
        while(selected->next!=nullptr)
        {
            if(i==index-1)
            {
                Dog* NewDog = new Dog();
                cout<<"insert breed:";
                cin>>NewDog->breed;
                cout<<"insert age:";
                cin>>NewDog->age;
                NewDog->next = selected->next;
                selected->next = NewDog;
                break;
            }
        selected = selected->next;
        i++;
        }

        if(selected->next==nullptr)
        {
            Dog* NewDog = new Dog();
            cout<<"insert breed:";
            cin>>NewDog->breed;
            cout<<"insert age:";
            cin>>NewDog->age;
            selected->next = NewDog;
        }
    }
    return first;
}

Dog* DelDog(Dog* first,int index){
    int i=0;
    Dog* selected = first;
    if(index==1)
    {
        selected = first->next;
        delete first;
        first = selected;
    }
    else
    {
        while(selected->next!=nullptr)
        {
            if(i==index-1)
            {
                Dog* temp = selected->next->next;
                delete selected->next; 
                selected->next = temp;  
                break;
            }
        selected = selected->next;
        i++;
        }
    }
    return first;
}

int main(){
    Dog* first = Load("file.txt");
    Print(first);
    first=DelDog(first,2);
    cout<<endl;
    Print(first);
}