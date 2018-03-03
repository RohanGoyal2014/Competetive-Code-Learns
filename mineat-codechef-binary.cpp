//MINEAT Problem...binary implementation of a complex problem
//taught by beerus
//10^9 was the upper limit, so 2^31=10^9
//thus if we continue to divide the interval continuously then at
//a point of time a state will occur when the
//answer has converged to a single point
//This stage may be reached before 31 times
//but I continued to make it work of 31 times since the answer dont change
//and continue to wrap around itself in next steps
#include<bits/stdc++.h>
using namespace std;
long long compute(long long a[],long n,long k)
{
    long long sum=0;
    for(long i=0;i<n;++i)
    {
        sum+=ceil(((double)(a[i]))/((double)k));
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        long n;
        long long h;
        cin>>n>>h;
        long long a[n];
        for(long i=0;i<n;++i)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        long long start=1;
        long long last=a[n-1];
        for(int i=1;i<=30;++i)
        {
            long long mid=(start+last)/2;
            if(compute(a,n,mid)>h)
            {
                start=mid+1;
            }
            else
            {
                last=mid;
            }
        }
        cout<<(start+last)/2<<endl;
    }
}
