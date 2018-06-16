#include<bits/stdc++.h>
#define m 1000000007
using namespace std;
struct plvl
{
    long long _11,_12,_21,_22;
};
void filter(long root,long par,vector<long> nbs[])
{
    vector<long> f;
    auto it=nbs[root].begin();
    bool allow=true;
    for(long i=0;i<nbs[root].size();++i)
    {
        if(nbs[root][i]!=par)
        {
            f.push_back(nbs[root][i]);
            filter(nbs[root][i],root,nbs);
        }
        else
        {
            allow=false;
        }
        if(allow)
        {
            it++;
        }
    }
    if(par!=0)
    {
        nbs[root].erase(it);
    }
}
plvl rec(long root,vector<long> nbs[],long src)
{
    long leafs=0;
    vector<plvl> v;
    for(long i=0;i<nbs[root].size();++i)
    {
        if(nbs[nbs[root][i]].empty())
        {
            leafs++;
        }
        else
        {
            v.push_back(rec(nbs[root][i],nbs,src));
        }
    }
    if(root==src)
    {
        return v[0];
    }
    plvl tmp;
    long long r1,r2;
    r1=r2=1;
    tmp._11=tmp._22=1;
    if(nbs[root].size()==leafs)
    {
        tmp._12=1;
        tmp._21=1;
        return tmp;
    }
    for(long i=0;i<v.size();++i)
    {
        tmp._11=(tmp._11*(v[i]._11+v[i]._12)%m)%m;
        tmp._22=(tmp._22*(v[i]._21+v[i]._22)%m)%m;
        r1=(r1*v[i]._21)%m;
        r2=(r2*v[i]._12)%m;
    }
    if(leafs)
    {
        tmp._12=tmp._22;
        tmp._21=tmp._11;
    }
    else
    {
        tmp._12=(tmp._22-r1)%m;
        tmp._21=(tmp._11-r2)%m;
        /*The most important factor
        to be remembered whenever you apply modulo anywhere*/
        if(tmp._12<0)
        {
            tmp._12+=m;
        }
        if(tmp._21<0)
        {
            tmp._21+=m;
        }
    }
    return tmp;
}
int main(){
    long n;
    cin>>n;
    if(n==2)
    {
        cout<<"2";
        return 0;
    }
    vector<long> nbs[n+1];
    long deg[n+1]={0};
    for(long i=0;i<n-1;++i)
    {
        long u,v;
        cin>>u>>v;
        nbs[u].push_back(v);
        nbs[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    long root;
    for(long i=1;i<=n;++i)
    {
        if(deg[i]==1)
        {
            root=i;;
            break;
        }
    }
    filter(root,0,nbs);
    plvl p=rec(root,nbs,root);
    p._11=(p._11*2)%m;
    cout<<p._11;
}