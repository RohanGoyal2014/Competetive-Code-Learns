#include<bits/stdc++.h>
using namespace std;
int bit(char ch)
{
    return ch-48;
}
int main()
{
    long n,q;
    cin>>n>>q;
    string s[n];
    for(long i=0;i<n;++i)
    {
        long long a;
        cin>>a;
        string bits=bitset<31>(a).to_string();
        s[i]=bits;
    }
    long status[n][31];
    for(int i=0;i<31;++i)
    {
        for(long j=0;j<n;++j)
        {
            if(j==0)
            {
                status[j][i]=bit(s[j][i]);
            }
            else
            {
                status[j][i]=bit(s[j][i])+status[j-1][i];
            }
        }
    }
    while(q--)
    {
        long l,r;
        cin>>l>>r;
        l--;
        r--;
        long arr[31];
        for(int i=0;i<31;++i)
        {
            if(l==0)
            {
                arr[i]=status[r][i];
                //cout<<arr[i];
            }
            else
            {
                arr[i]= status[r][i] - status[l-1][i];
                //cout<<arr[i];
            }
        }
        for(int i=0;i<31;++i)
        {
            //cout<<arr[i];
            if(arr[i]>((r-l+1)/2))
            {
                arr[i]=0;
            }
            else if(arr[i]==(r-l+1)/2&&(r-l+1)%2==0)
            {
                arr[i]=0;
            }
            else
            {
                arr[i]=1;
            }
        }
        //cout<<endl;
        long long sum=0;
        long long f=1;
        for(long i=30;i>=0;--i)
        {
            sum+=arr[i]*f;
            f*=2;
        }
        cout<<sum<<endl;
    }
 
} 
