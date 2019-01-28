/*
 * Kruskal's Algorithm
 * Disjoint Set Implementation(Rank+Path Compression)
 * Question: https://www.spoj.com/problems/MST/
 *
 * */

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define mkp(a,b) make_pair(a,b)
#define PI 3.14159265359
#define eb emplace_back
#define mod (long long)(1e9+7)
#define FILE_READ freopen("input.txt","r",stdin)
#define FILE_WRITE freopen("output.txt","w",stdout)
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long ul;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef long double ld;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
template <class T> void swap(T&a,T &b) { T c=a; a=b; b=c; }

class node
{
public:
    int parent;
    int data;
    int rank=1;
    node()=default;
    node(int data)
    {
        this->data=data;
        parent=data;
    }
};
void makeSet(node &nd,int i)
{
    nd=node(i);
}
int findSet(int i,node nd[])
{
    if(i!=nd[i].parent)  nd[i].parent=findSet(nd[i].parent,nd);
    return nd[i].parent;
}
int unionSets(int a,int b,node nd[])
{
    //this returns 1 if union is possible and is done
    //otherwise returns 0

    int par1=findSet(a,nd);
    int par2=findSet(b,nd);
    if(par1==par2) return 0;
    if(nd[par1].rank>nd[par2].rank)
    {
        nd[par2].parent=par1;
    }
    else if(nd[par1].rank<nd[par2].rank)
    {
        nd[par1].parent=par2;
    }
    else
    {
        nd[par1].parent=par2;
        nd[par2].rank++;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    FILE_READ;
//    FILE_WRITE;

    int n,m;
    cin>>n>>m;
    vector<pair<int,pii>> edges(m);
    node nd[n+1];
    for(int i=1;i<=n;++i)
    {
        makeSet(nd[i],i);
    }
    for(int i=0;i<m;++i)
    {
        cin>>edges[i].second.first>>edges[i].second.second>>edges[i].first;
    }
    sort(edges.begin(),edges.end());
    ll ans=0;
    for(auto i:edges)
    {
        if(unionSets(i.second.first,i.second.second,nd))
        {
            ans+=i.first;
        }
    }
    cout<<ans;

    return 0;
}