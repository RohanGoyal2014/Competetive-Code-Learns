#include <bits/stdc++.h>
//Link:http://codeforces.com/contest/1072/problem/B
//Rohan Talwar's solution
using namespace std;

int main()
{
    int n,i;
    cin>>n;
    int a[n-1],b[n-1];
    for(i=0;i<n-1;i++) cin>>a[i];
    for(i=0;i<n-1;i++) cin>>b[i];
    for(i=0;i<n-1;i++)
    {
        if(a[i]<b[i])
        {
            cout<<"NO"<<'\n';
            return 0;
        }
    }

    int t[n];
    for(int j=0;j<4;j++){
        t[0]=j;
        for(i=1;i<n;i++)
            t[i]=a[i-1]+b[i-1]-t[i-1];
        int sw=1;
        for(i=0;i<n-1;i++)
        {
            if((t[i]|t[i+1])!=a[i] || (t[i]&t[i+1])!=b[i]  || t[i+1]<0 || t[i+1]>3)
            {  //cout<<i<<" "<<t[i]<<" "<<t[i+1]<<" "<<t[i]<<'\n';
                sw=0;
                break;
            }

        }
        if(sw==1)
        {
            cout<<"YES"<<'\n';
            for(i=0;i<n;i++)
                cout<<t[i]<<' ';
            return 0;
        }
    }
    cout<<"NO"<<'\n';
}
