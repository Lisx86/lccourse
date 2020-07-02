#include <iostream>
#include <string.h>
using namespace std;

const char* input = R"(The   fox jumped   over    the log.)";

int main()
{
    char* correct = new char[strlen(input)];
    strcpy(correct,input);
    cout<<correct<<endl;
    int start;
    for(int i=0;i<=strlen(correct);i++)
    {
        if(correct[i]==' ')
        {
            start=i;
            while(correct[i+1]==' ')
            {
                i++;
            }
            strcpy(correct+start,correct+i);
        }
    }

    cout<<correct;
    delete[] correct;
}