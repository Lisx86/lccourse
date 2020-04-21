#include <iostream>
using namespace std;

int mas[1000];

int main()
{
    int n=0,temp=0,result=0;
    
    while(mas[n]!=-1)
    {
        n++;
        cout<<"Insert value for mas["<<n<<"]=";
        cin>>mas[n];  
    }
	
    for(int i=1;i<=n;i++)
    {
	    if(mas[i]==0)
	    {
	        temp++;
	        for(int j=i+1;j<=n;j++)
	    	{
                if(mas[j]==0)
                {
                    temp++;
                }
                else
                {
                    if(result<temp)
                    {
                        result=temp;
                        temp=0;
                        break;
                    }
                    else
                    {
                        temp=0;
                        break;
                    }
                }
	    	}
    	}
    }
    cout<<"Zero repeated consecutivly "<<result<<" times"<<endl;
}

    

