/*

Square Root Decomposition of a tree level wise
An Idea can be derived from attached image


*/

#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back 
using namespace std;

set<int> blockParents;
int bpmap[200001];

void dfs(int root,int par,vector<int> nbs[],int level[],int bsz,int parent[])
{
    if(bsz!=-1)
    {
        // cout<<bsz<<endl;
        if((level[root]+1)%bsz==0)
        {
            blockParents.insert(root);
            bpmap[root]=1;
        }            
    }
    else 
    {
        parent[root]=par;
        level[root]=level[par]+1;
    }
    bool exec=false;
    for(auto i:nbs[root])
    {
        if(i!=par)
        {
            exec=true;
            dfs(i,root,nbs,level,bsz,parent);
        }
    }
    if(!exec && bsz!=-1)
    {
        bpmap[root]=1;
        blockParents.insert(root);
    }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(bpmap,0,sizeof bpmap);
    bpmap[0]=1;
    int n,q;
    cin>>n>>q;
    ll val[n+1];
    for(int i=1;i<=n;++i)
    {
        cin>>val[i];
    }
    vector<int> nbs[n+1];
    for(int i=0;i<n-1;++i)
    {
        int u,v;
        cin>>u>>v;
        nbs[u].eb(v);
        nbs[v].eb(u);
    }
    vector<ll> v[n+1];
    int level[n+1];
    int parent[n+1]={0};
    memset(level,0,sizeof level);
    dfs(1,0,nbs,level,-1,parent);
    int blockSize=sqrt(*max_element(level,level+n+1));
    dfs(1,0,nbs,level,blockSize,parent);
    // for(int i=1;i<=n;++i) cout<<parent[i]<<" ";
    int nextBlockPar[n+1]={0};
    for(auto i:blockParents)
    {
        // cout<<"for "<<i<<endl;
        v[i].eb(val[i]);
        auto j=parent[i];
        while(bpmap[j]!=1)
        {
            // cout<<j<<" ";;
            v[i].eb(val[j]);
            j=parent[j];
        }
        nextBlockPar[i]=j;
        // cout<<endl;
    }
    for(int i=1;i<=n;++i)
    {
        if(!v[i].empty()) sort(v[i].begin(),v[i].end());
    }
    // for(int i=1;i<=n;++i) cout<<nextBlockPar[i]<<" ";
    // return 0;
    while(q--)
    {
        ll u,x;
        cin>>u>>x;
        int ans=0;
        int _=u;
        while(bpmap[u]!=1)
        {
            // cout<<"#";
            // cout<<u<<" ";
            if(val[u]<=x) ++ans;
            u=parent[u];
        }
        while(u!=0)
        {
            // cout<<"*";
            int content=upper_bound(v[u].begin(),v[u].end(),x)-v[u].begin();
            ans+=content;
            u=nextBlockPar[u];
        }
        cout<<ans<<endl;
    }
    
}
