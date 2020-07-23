#include <iostream>
#include<bits/stdc++.h>  
using namespace std;

struct VolCalculator
{
    int Vol;
    VolCalculator(int arr[],int n)
    {   
        Vol=0;
        for (int i = 1; i < n-1; i++) 
        { 
            int left = arr[i]; 
            for (int j=0; j<i; j++) 
                left = max(left, arr[j]); 
              
            int right = arr[i]; 
            for (int j=i+1; j<n; j++) 
                right = max(right, arr[j]);  
               
            Vol = Vol + (min(left, right) - arr[i]);    
        } 
    }
    int GetVol()
    {
        return Vol;
    }
};

int main()
{
    int n[21]={1,2,3,4,3,2,2,4,8,16,15,14,14,15,2,2,4,4,5,6,6};
    VolCalculator a(n,21);
    cout<<a.GetVol();
}