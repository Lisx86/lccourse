#include <iostream>
#include <string.h>
using namespace std;

int N1,N2;
char* S1 = new char[20];
char* S2 = new char[20];

int main()
{
    cout<<"Please insert the two integers:"<<endl;
    cout<<"N1:";
    cin>>N1;
    cout<<"N2:";
    cin>>N2;
    cout<<"Now please insert the two strings:"<<endl;
    cout<<"S1:";
    cin>>S1;
    cout<<"S2:";
    cin>>S2;

    char* S3 = new char[N1+N2];

    for(int i=0;i<=N1-1;i++)
    {
        memcpy(S3+i,S1+i,1);
    }
    
    for(int i=0;i<=N2-1;i++)
    {
        memcpy(S3+N1+i,S2+i,1);
    }
    
    cout<<S3;
    
    delete[] S3;
}