#include <iostream>
#include <string.h>
#include <bits/stdc++.h> 
using namespace std;

const char* input = R"(   {}  () [({)}]   )";

char open[5]={'(','[','{'};
char close[5]={')',']','}'};
  
int main () 
{ 
    stack <char> s; 
    stack <int> m;
    for(int i=0;i<=strlen(input);i++)
    {
        for(int j=0;j<=2;j++)
        {
            if(input[i]==open[j])
            {
                s.push(open[j]);
                m.push(j);
            }

            if(input[i]==close[j])
            {
                if(input[i]==close[m.top()])
                {
                    m.pop();
                    s.pop();
                }
                else
                {
                    cout<<i+1;
                    return i;
                }
            }
        }
    }
    cout<<"0";
    return 0; 
}