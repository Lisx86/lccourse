#include <iostream>
using namespace std;

int main()
{
    int arr[]={1,5,-1,5};
    int n=sizeof(arr)/sizeof(arr[0]);

    uint64_t variants=(1<<n);
    int result,combination;

    for(int i=0;i<=n;i++)
    {
        if(arr[0]==0)
        {
            cout<<"the sum:0 the number:0"<<endl;
            return 0;
        }
    }

    int mem=0,sum=0;
    for(uint64_t i=1;i<=variants-1;i++)
    {
        //cout<<i<<")";
        for(uint64_t j=1;j<=variants/2;j=j*2)
        {
            //cout<<j<<" ";
            //cout<<(j&i)<<" "<<(1<<mem)<<"     ";
            if((j&i)==(1<<mem))
            {
                //cout<<"true ";
                sum=sum+arr[mem];
            }
            mem++;
        }
        //cout<<endl;
        cout<<sum<<" ";

        if(abs(sum)<abs(result))
        {
            result=sum;
            combination=i;
        }

        mem=0;
        sum=0;
    }

    cout<<"the sum:"<<result<<" the numbers:";
    for(uint64_t j=1;j<=variants;j=j*2)
    {
        if((combination&j)==j)
        {
            cout<<arr[mem]<<" ";
        }
        mem++;
    }
}