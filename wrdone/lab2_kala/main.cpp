#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>
#include <bits/stdc++.h> 
#include <cstring>
#include <cstdlib>
using namespace std;
wstring arr[1000000];
string del[10]={".","-","=","+","_","?","!","\"","'",","};
int n,i=0;

int main(int argc, char** argv)
{
    n=atoi(argv[argc-1]);
    int len,comp=0,test=0;
    wifstream f("words2.txt");

    //////////////////////////////////
    while(f.eof()!=true)
    {
        f>>arr[i];
        transform(arr[i].begin(),arr[i].end(),arr[i].begin(), ::tolower);

        len = arr[i].length();

        //length validation WORKING
        if(arr[i].length()<n)
        {
            comp++;
        }

        //polindrom validation WORKING
        for(int j=0;j<=len;j++)
        {   
            if(arr[i][j]==arr[i][len-1-j])
            {
                test++;
            }
            if(test==len)
            {
                comp++;
            }
        }

        test=0;
        
        //duplication validation WORKING
        for(int j=0;j<=i-1;j++)
        {
            if(arr[i]==arr[j])
            {
                comp++;
                break;
            }
        }

        if(comp==0)
        {
            i++;
        }
        comp=0;
    }
    ///////////////////////////////////////////

    //////////////////last introduced character
        f>>arr[i];
        len = arr[i].length();

        //length validation WORKING
        if(arr[i].length()<n)
        {
            comp++;
        }

        //polindrom validation WORKING
        for(int j=0;j<=len;j++)
        {   
            if(arr[i][j]==arr[i][len-1-j])
            {
                test++;
            }
            if(test==len)
            {
                comp++;
            }
        }

        test=0;
        
        //duplication validation WORKING
        i--;
        for(int j=1;j<=i-1;j++)
        {
            if(arr[i]==arr[j])
            {
                comp++;
                break;
            }
        }

        if(comp==0)
        {
            i++;
        }
        comp=0;

    ////////////////////////////////////////////

    ////////result
    for(int x=0;x<=i;x++)
    {
        int lenx=arr[x].length();

        for(int y=x+1;y<=i;y++)
        {
            int leny=arr[y].length();
            if((arr[x].substr(0,n)==arr[y].substr(leny-n,leny)) || (arr[x].substr(lenx-n,lenx)==arr[y].substr(0,n)))
            {
                wcout<<arr[x]<<" "<<arr[y]<<endl;
            }
        }
    }
    f.close();
    /*
   const char* a = "bcde";
    char* w = new char[5]; 

    int j=3;
    for(int i=0;i<=3;i++)
    {
      //  strncpy(w+i,a+j,1);
        w[i]=a[j];
        j--;
    }

    w[4]  = '\0';
    cout<<a<<endl<<w<<endl;
    */
}

