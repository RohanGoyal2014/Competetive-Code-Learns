/*
 *AND Logic Question
 * Link:https://www.hackerearth.com/challenge/competitive/december-circuits-18/algorithm/submatrix-queries-7e459f97/
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    FILE_READ;
//    FILE_WRITE;

    int n;
    cin>>n;
    int a[n];
    int pre[n+1][256];
    memset(pre,0,sizeof pre);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        pre[i+1][a[i]]++;
        for(int j=0;j<256;++j)
        {
            pre[i+1][j]+=pre[i][j];
        }
    }
    int m;
    cin>>m;
    while(m--)
    {
        int l,r,x;
        cin>>l>>r>>x;
        vector<pair<int,ll>> mp1;
        ll mp2[256]={0};
        for(int i=0;i<256;++i)
        {
            if((i&x)==x && (pre[r][i]-pre[l-1][i])>0)
            {
                mp1.eb(i,((pre[r][i]-pre[l-1][i])%mod));
            }
        }
        for(auto i:mp1)
        {
            for(auto j:mp1)
            {
                mp2[(i.first&j.first)]=(mp2[(i.first&j.first)]+((i.second*j.second)%mod))%mod;
            }
        }
        ll ans=0;
        for(auto i=0;i<256;++i)
        {
            if(mp2[i]==0) continue;
            for(auto j:mp1)
            {
                if((i&(j.first))==x)
                {
                    ans=(ans+((mp2[i]*j.second)%mod))%mod;
                }
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}