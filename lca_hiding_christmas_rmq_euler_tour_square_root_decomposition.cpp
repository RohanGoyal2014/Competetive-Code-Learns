/*
 * There are N houses in a city connected by exactly N - 1 roads. There is exactly 1 shortest path from any house to any
 * other house. The houses are numbered from 1 to N.
 * Since Christmas is about to come so Santa has decided to hide gifts in these houses.
 * Santa will come to the city for M consecutive days. Each day he will come to a house a first and will go till house
 * b hiding a gift in each house that comes in the path.
 *Can you tell the maximum number of gifts any house has after M days.
 *
 * The solution uses:
 * LCA using euler tour and then implementing RMQ using square root decomposition
 * overall complexity is m*n(1/2)
 * other approaches like segment tree took much time to build causing tle
 * also sparse array method will obviously give stack overflow.
 * Thus this is an optimised approach
 * n,m was 10^5 in worst case
 * */
#include<bits/stdc++.h>
using namespace std;
void bfs(long root,vector<long> a[],long level[],vector<long> lvl[],long par,vector<long> &euler,long parent[])
{
    euler.push_back(root);
    for(long i=0;i<a[root].size();++i)
    {
        if(a[root][i]!=par)
        {
            parent[a[root][i]]=root;
            level[a[root][i]]=level[root]+1;
            lvl[level[root]+1].push_back(a[root][i]);
            bfs(a[root][i],a,level,lvl,root,euler,parent);
            euler.push_back(root);
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
    for(long i=0;i<n-1;++i)
    {
        long u,v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    long level[n+1]={0};
    long parent[n+1]={0};
    vector<long> lvl[n+1];
    vector<long> euler;
    long foi[n+1]={0};
    parent[1]=-1;
    level[1]=1;
    lvl[1].push_back(1);
    bfs(1,a,level,lvl,-1,euler,parent);
    for (long i=euler.size()-1;i>=0;--i)
    {
        foi[euler[i]]=i;
    }
    // cout<<"The fois are:\n";
    // for(long i=1;i<=n;++i)
    // {
    //     cout<<foi[i]<<" ";
    // }
    // cout<<endl;
    long state[100001]={0};
    long sq=ceil(sqrt((long double)euler.size()));
    long no_of_blocks=ceil(((long double)euler.size())/(long double)sq);
    long min_block[no_of_blocks];
    //cout<<no_of_blocks<<endl;
    // cout<<euler.size()<<endl;
    // for(long i=0;i<euler.size();++i)
    // {
    //     cout<<euler[i]<<" ";
    // }
    //cout<<endl;
    for(long i=0;i<no_of_blocks;++i)
    {
        min_block[i]=LONG_MAX;
    }
    for(long i=0;i<euler.size();++i)
    {
        long block=(i)/(long)sq;
        //cout<<block<<endl;
        long alr_lvl;
        if(min_block[block]==LONG_MAX)
        {
            alr_lvl=LONG_MAX;
        }
        else
        {
            alr_lvl=level[min_block[block]];
        }
        //cout<<min[block]<<"\n";
        if(level[euler[i]]<alr_lvl)
        {
            min_block[block]=euler[i];
        }
    }
    // for(long i=0;i<no_of_blocks;++i)
    // {
    //     cout<<min_block[i]<<" ";
    // }
    // cout<<endl;
    map<pair<long,long>,long> mp;
    for(long i=0;i<m;++i)
    {
        long u,v;
        cin>>u>>v;
        long tmp=u;
        u=min(u,v);
        v=max(tmp,v);
        pair<long,long> p=make_pair(u,v);
        if(mp.find(p)==mp.end())
        {
            mp[p]=1;
        }
        else
        {
            mp[p]++;
        }
    }
    for(auto i=mp.begin();i!=mp.end();++i)
    {
        long u,v;
        u=i->first.first;
        v=i->first.second;
        long val=i->second;
        //cout<<u<<" "<<v<<":"<<val<<endl;
        //cin>>u>>v;
        if(foi[v]<foi[u])
        {
            long tmp=u;
            u=v;
            v=tmp;
        }
        long start_block=foi[u]/((long)sq);
        long end_block=foi[v]/((long)sq);
        long k=LONG_MAX;//k is lca
        if(start_block==end_block)
        {
            //cout<<"type 1 ";
            for(long j=foi[u];j<=foi[v];++j)
            {
                long alr_level;
                if(k==LONG_MAX)
                {
                    alr_level=LONG_MAX;
                }
                else
                {
                    alr_level=level[k];
                }
                if(alr_level>level[euler[j]])
                {
                    k=euler[j];
                }
            }
        }
        else if(start_block+1==end_block)
        {
            //cout<<"type 2 ";
            long mod1=foi[u]%(long)sq;
            long mod2=foi[v]%(long)sq;
            if(mod1==0 && mod2==((long)sq-1))
            {
                if(level[min_block[start_block]]<level[min_block[end_block]])
                {
                    k=min_block[start_block];
                }
                else
                {
                    k=min_block[end_block];
                }
            }
            else if(mod1==0)
            {
                k=min_block[start_block];
                for(long j=end_block*((long)sq);j<=foi[v];++j)
                {
                    if(level[euler[j]]<level[k])
                    {
                        k=euler[j];
                    }
                }
            }
            else if(mod2==((long)sq-1))
            {
                k=min_block[end_block];
                for(long j=foi[u];j<(start_block+1)*((long)sq);++j)
                {
                    if(level[euler[j]]<level[k])
                    {
                        k=euler[j];
                    }
                }
            }
            else
            {
                for(long j=foi[u];j<=foi[v];++j)
                {

                    long alr_level;
                    if(k==LONG_MAX)
                    {
                        alr_level=LONG_MAX;
                    }
                    else
                    {
                        alr_level=level[k];
                    }
                    if(alr_level>level[euler[j]])
                    {
                        k=euler[j];
                    }
                }
            }
        }
        else
        {
            //cout<<"type 3\n";
            //cout<<"the fois are"<<foi[u]<<" and "<<foi[v]<<endl;
            long mod1=foi[u]%(long)sq;
            long mod2=foi[v]%(long)sq;
            //cout<<mod1<<" "<<mod2<<endl;
            long block_1=start_block,block_2=end_block;
            if (mod1 != 0)
            {
                block_1 = start_block + 1;
            }
            if (mod2 != ((long)sq-1))
            {
                //cout<<"end block dec\n";
                block_2 = end_block - 1;
            }
            for(long j=block_1;j<=block_2;++j)
            {
                long alr_lvl;
                if(k==LONG_MAX)
                {
                    alr_lvl=LONG_MAX;
                }
                else
                {
                    alr_lvl=level[k];
                }
                if(level[min_block[j]]<alr_lvl)
                {
                    k=min_block[j];
                }
            }
            //cout<<"k is:"<<k<<endl;
            if(block_1!=start_block)
            {
                for (long j = foi[u]; j < (start_block + 1) * ((long) sq); ++j)
                {
                    if (level[euler[j]] < level[k])
                    {
                        k = euler[j];
                    }
                }
            }
            if(block_2!=end_block)
            {
                for (long j = end_block * ((long) sq); j <= foi[v]; ++j)
                {
                    if (level[euler[j]] < level[k])
                    {
                        k = euler[j];
                    }
                }
            }
        }
        //cout<<k<<endl;
        if(k==u)
        {
            state[v]+=val;
            long par=parent[u];
            if(par!=-1)
            {
                state[par]-=val;
            }
            continue;
        }
        if(k==v)
        {
            state[u]+=val;
            long par=parent[v];
            if(par!=-1)
            {
                state[par]-=val;
            }
            continue;
        }
        state[u]+=val;
        state[v]+=val;
        long par=parent[k];
        if(par!=-1)
        {
            state[par]-=val;
        }
        state[k]-=val;
    }
    long max_level;
    for(long i=1;i<=n;++i)
    {
        if(lvl[i].empty())
        {
            break;
        }
        max_level=i;
    }
    for(long i=max_level;i>=1;--i)
    {
        for(long j=0;j<lvl[i].size();++j)
        {
            long par=parent[lvl[i][j]];
            if(par!=-1)
            {
                state[par]+=state[lvl[i][j]];
            }
        }
    }
    cout<<*max_element(state+1,state+n+1);
}