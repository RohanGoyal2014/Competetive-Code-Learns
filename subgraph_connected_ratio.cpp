//Approximating Problem
//This is to find the edges to be removed to create a subgraph
//such that ratio sum of shortest distance of all nodes from one another of
//subgraph to the sum of shortest distance of all nodes from one another in
//graph is maximum
//The approach that I used is that i started removing the smallest weighted edges from
//the graph and checked if it is connected or not
#include<bits/stdc++.h>
using namespace std;
struct edge
{
    long u;
    long v;
    long long w;
};
bool compare(edge a,edge b)
{
    return a.w<b.w;
}
void dfs(long n,bool exists[][130],long root,int visited[])
{
    visited[root]=1;
    //cout<<"Visited"<<root<<endl;
    for(int i=0;i<n;++i)
    {
        if(exists[root][i])
        {
            //cout<<root<<" "<<i<<endl;
            if(visited[i]==0)
            {
                dfs(n, exists, i, visited);
            }
        }
    }
    //cout<<root<<" ended\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long n,k;
    cin>>n>>k;
    long long a[130][130];
    bool exists[130][130];
    vector<edge> v;
    for(long i=0;i<n;++i)
    {
        for(long j=0;j<n;++j)
        {
            cin>>a[i][j];
            if(a[i][j]==0)
            {
                exists[i][j]=false;
            }
            else
            {
                exists[i][j]=true;
            }
            if(i<j)
            {
                edge e;
                e.u=min(i,j);
                e.v=max(i,j);
                e.w=a[i][j];
                v.push_back(e);
            }
        }
    }
    sort(v.begin(),v.end(),compare);
    vector<edge> soln;
    long count=0;
    for(long i=0;i<v.size();++i)
    {
        int visited[130]={0};
        exists[v[i].u][v[i].v]=!exists[v[i].u][v[i].v];
        exists[v[i].v][v[i].u]=!exists[v[i].v][v[i].u];
        dfs(n,exists,0,visited);
        bool isConnected=true;
        for(int j=0;j<n;++j)
        {
            if(visited[j]==0)
            {
                isConnected=false;
                break;
            }
        }
        if(!isConnected)
        {
            //cout<<"Not connected\n";
            exists[v[i].u][v[i].v]=!exists[v[i].u][v[i].v];
            exists[v[i].v][v[i].u]=!exists[v[i].v][v[i].u];
        }
        else
        {
            //cout<<"Connected\n";
            soln.push_back(v[i]);
        }
        if(soln.size()==k)
        {
            //cout<<"Broken";
            break;
        }
    }
    cout<<soln.size()<<endl;
    for(long i=0;i<soln.size();++i)
    {
        cout<<soln[i].u+1<<" "<<soln[i].v+1<<endl;
    }
}