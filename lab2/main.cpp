#include <iostream>
#include <fstream>
#include <string>

using namespace std;
string arr[1000000];
int n=1,i=1;

int main(int n)
{
    ifstream f("words.txt");
    while(f.eof()!=true)
    {
        f>>arr[i];
        i++;
    }

    for(int j=1;j<=i;j++)
    {
        cout<<arr[j]<<" ";
    }
    f.close();
}

