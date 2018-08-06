/*
https://www.geeksforgeeks.org/multiply-large-integers-under-large-modulo/
codechef code:gcdmod
*/
#include<bits/stdc++.h>
#define m 1000000007
using namespace std;
long long mod_product(long long a,long long b,long long mod)
{
    long long res=0;
    while(b)
    {
        if(b%2==1)
        {
            res=(res+a)%mod;
        }
        b/=2;
        a=(2*a)%mod;
    }
    return res;
}
long long mod_exponent(long long a,long long n,long long mod)
{
    long long res=1;
    a=a%mod;
    while(n!=0)
    {
        if(n%2==1)
        {
            res=mod_product(a,res,mod);
            if(res<0 && mod!=m)
            {
                cout<<1/0;
            }
        }
        n/=2;
        a=mod_product(a,a,mod);
    }
    return res;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long a,b,n;
        cin>>a>>b>>n;
        long long d=abs(a-b);
        if(d==0)
        {
            long long at=mod_exponent(a,n,m);
            cout<<(2*at)%m<<endl;
            continue;
        }
        long long e=mod_exponent(min(a,b),n,d);
        e=(2*e)%d;
        while(e!=0)
        {
            long long tmp=d%e;
            d=e;
            e=tmp;
        }
        cout<<d<<endl;
    }
}
