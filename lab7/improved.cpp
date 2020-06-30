#include <iostream>
#include <string.h>
using namespace std;

const char* input = R"(fsdafasdf
sgfsdfgs
dfdsa
fdsa
dsfasdfa
sdfasd
fads)";

int main ()
{
    char* lines[20];
    for(int i=0;i<=20;i++)
    {
        lines[i]=new char[20];
    }

    int len=0,value=0,line_number=0;
    while(input[len]!='\0')
    {
        value = strcspn(input+len,"\n");
        cout<<len<<" "<<value<<endl;
        memcpy(lines[line_number],input+len,value);
        line_number++;
        len=len+value+1;
    }

    for(int i=0;i<=line_number;i++)
    {
        if(strlen(lines[i])<5)
        {
            for(int j=i;j<=line_number-1;j++)
            {
                strcpy(lines[j],lines[j+1]);
            }
            line_number--;
        }
    }

    char* temp = new char[20];
    for(int i=0;i<=line_number;i++)
    {
        if(strlen(lines[i])<strlen(lines[i+1]))
        {
            strcpy(temp,lines[i]);
            strcpy(lines[i],lines[i+1]);
            strcpy(lines[i+1],temp);
            i=0;
        }
    }

    for(int i=0;i<=line_number;i++)
    {
        cout<<lines[i]<<endl;
    }

    for(int i=0;i<=20;i++)
    {
        delete[] lines[i];
    }
    delete[] temp;
}
