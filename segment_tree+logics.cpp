/*
 * Codechef problem :KCOMPRES
 * best tc to check:
 * 1
 * 6 12
 * 123 351 351 53 54 455
 * ans:2
 * */
#include<bits/stdc++.h>
using namespace std;
typedef long l;
typedef pair<l,l> pll;
pll build_max_tree(l start,l end,l a[],l node,pll tree[])
{
    if(start==end)
    {
        tree[node].first=a[start];
        tree[node].second=start;
        return tree[node];
    }
    l mid=(start+end)/2;
    pll left=build_max_tree(start,mid,a,2*node,tree);
    pll right=build_max_tree(mid+1,end,a,2*node+1,tree);
    if(left.first>=right.first)
    {
        tree[node].first=left.first;
        tree[node].second=left.second;
    }
    else
    {
        tree[node].first=right.first;
        tree[node].second=right.second;
    }
    return tree[node];
}
pll update_max_tree(l start,l end,l pos,l a[],l node,pll tree[])
{
    if(start==end)
    {
        tree[node].first=a[start];
        return tree[node];
    }
    l mid=(start+end)/2;
    pll left,right;
    if(pos<=mid)
    {
        pll tmp=update_max_tree(start,mid,pos,a,2*node,tree);
        left.first=tmp.first;
        left.second=tmp.second;
        right.first=tree[2*node+1].first;
        right.second=tree[2*node+1].second;
    }
    else
    {
        pll tmp=update_max_tree(mid+1,end,pos,a,2*node+1,tree);
        left.first=tree[2*node].first;
        left.second=tree[2*node].second;
        right.first=tmp.first;
        right.second=tmp.second;
    }
    if(left.first>=right.first)
    {
        tree[node].first=left.first;
        tree[node].second=right.second;
    }
    else
    {
        tree[node].first=right.first;
        tree[node].second=right.second;
    }
    return tree[node];
}
pll query_max_tree(l start,l end,l node,l L,l R,pll tree[])
{
    if(L>end || R<start)
    {
        return make_pair(-1,-1);
    }
    if(L<=start && end<=R)
    {
        return tree[node];
    }
    l mid=(start+end)/2;
    pll left=query_max_tree(start,mid,2*node,L,R,tree);
    pll right=query_max_tree(mid+1,end,2*node+1,L,R,tree);
    if(left.second==-1)
    {
        return right;
    }
    if(right.second==-1)
    {
        return left;
    }
    if(left.first>=right.first)
    {
        return left;
    }
    return right;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        l n,s;
        cin>>n>>s;
        l a[n+1];
        map<l,vector<l>> mp;
        for(l i=1;i<=n;++i)
        {
            cin>>a[i];
            mp[a[i]].push_back(i);
        }
        l start=0;
        l end=n;
        l last_k=-1;
        while(start<=end)
        {
            l k=(start+end)/2;
            l sum=0;
            l b[n+1]={0};
            pll tree[5*n];
            build_max_tree(1,n,b,1,tree);
            // cout<<"for "<<k<<":\n";
            for(auto i=mp.begin();i!=mp.end();++i)
            {
                if(sum>s)
                {
                    break;
                }
                vector<l> gp;
                gp.push_back(i->second[0]);
                for(l j=1;j<i->second.size();++j)
                {
                    if(i->second[j]-i->second[j-1]<=k)
                    {
                        gp.push_back(i->second[j]);
                    }
                    else
                    {
                        l front=max(1l,gp[0]-k);
                        l rear=min(n,gp[gp.size()-1]+k);
                        pll max_b=query_max_tree(1,n,1,front,rear,tree);
                        // cout<<"matched from "<<gp[0]<<" "<<gp[gp.size()-1]<<endl;
                        for(l m=0;m<gp.size();++m)
                        {
                            b[gp[m]]=max_b.first+1;
                        }
                        gp.clear();
                        gp.push_back(i->second[j]);
                    }
                }
                l front=max(1l,gp[0]-k);
                l rear=min(n,gp[gp.size()-1]+k);
                pll max_b=query_max_tree(1,n,1,front,rear,tree);
                // cout<<max_b.first<<" "<<max_b.second<<")\n";
                // cout<<"matched from "<<gp[0]<<" "<<gp[gp.size()-1]<<endl;
                for(l m=0;m<gp.size();++m)
                {
                    b[gp[m]]=max_b.first+1;
                }
                for(l j=0;j<i->second.size();++j)
                {
                    sum+=b[i->second[j]];
                    // cout<<b[i->second[j]]<<" ";
                    if(sum>s)
                    {
                        // cout<<"broken flow\n";
                        break;
                    }
                    update_max_tree(1,n,i->second[j],b,1,tree);
                }
            }
            if(sum<=s)
            {
                last_k=k;
                start=k+1;
            }
            else
            {
                end=k-1;
            }
        }
        cout<<last_k+1<<endl;
    }
}