//N preprocessing for building tree rather accessing levels
//logN time to reach same level and love up until the values become common
//The target was to find maximum valued state at the end when all nodes from path u to v
//are incremented by 1.
#include<bits/stdc++.h>
using namespace std;
void build_tree(vector<long> a[],long root,long level[],long store_parent[])
{
    for(long i=0;i<a[root].size();++i)
    {
        if(a[root][i]!=store_parent[root])
        {
            level[a[root][i]]=level[root]+1;
            store_parent[a[root][i]]=root;
            build_tree(a,a[root][i],level,store_parent);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long n,m;
    cin>>n>>m;
    vector<long> a[n+1];
    long level[100005];
    long store_parent[100005];
    long state[100005]={0};
    for(long i=0;i<n-1;++i)
    {
        long u,v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    level[1]=1;
    store_parent[1]=-1;
    build_tree(a,1,level,store_parent);
    for(long i=0;i<m;++i)
    {
        long u,v;
        cin>>u>>v;
        while(level[u]>level[v])
        {
            state[u]++;
            u=store_parent[u];
        }
        while(level[u]<level[v])
        {
            state[v]++;
            v=store_parent[v];
        }
        while(u!=v)
        {
            state[u]++;
            state[v]++;
            u=store_parent[u];
            v=store_parent[v];
        }
        state[u]++;
    }
    cout<<*max_element(state,state+n+2);
}
