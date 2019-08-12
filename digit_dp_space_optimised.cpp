/*
 * Space optimised DigitDP
 * Problem:  https://www.codechef.com/AUG19A/problems/ENCODING
 *
 * */
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define     mkp(a,b)    make_pair(a,b)
#define     PI          3.14159265359
#define     ll              long long
#define     ul              unsigned long long
#define     ld              long double
#define     mset(arr,val)   memset(arr,val,sizeof arr)
#define     MAXN            (long long)2e5+5
#define     eb              emplace_back
#define     mod             (long long)(1e9+7)
#define     FILE_READ       freopen("input.txt","r",stdin)
#define     FILE_WRITE      freopen("output.txt","w",stdout)
using namespace std;
using namespace __gnu_pbds;;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

pll dp[MAXN][2][10];
ll ____pow10[MAXN];

void pre() {
    ____pow10[0]=1;
    for(int i=1;i<MAXN;++i) {
        ____pow10[i] = (____pow10[i-1]*10ll)%mod;
    }
}

pll solve(int idx,int tight, int prev,string &str) {
//    cout<<"at "<<idx<<" "<<tight<<" "<<prev<<endl;
    if(idx==-1) return {0ll,1ll};
    if(dp[idx][tight][prev].first!=-1 && tight!=1) {
//        cout<<"cache:"<<dp[idx][tight][prev].first<<" "<<dp[idx][tight][prev].second<<endl;
        return dp[idx][tight][prev];
    }
    int k=9;
    if(tight) {
        k=str[idx]-'0';
    }
    ll ans=0;
    ll c=0;
    for(int i=0;i<=k;++i) {
        int newTight = tight && (i==(str[idx]-'0'));
        pll res = solve(idx-1,newTight,i,str);
        if(i!=prev) {
            res.first=(((((____pow10[idx]*i)%mod)*res.second)%mod)+res.first)%mod;
        }
        c=(c+res.second)%mod;
        ans=(ans+res.first)%mod;
    }
//    cout<<ans<<endl;
    dp[idx][tight][prev].first=ans;
    dp[idx][tight][prev].second=c;
    return dp[idx][tight][prev];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    FILE_READ;
//    FILE_WRITE;

    pre();

    int t;
    cin>>t;
    for(int i=0;i<MAXN;++i) {
        for(int j=0;j<2;++j) {
            for(int k=0;k<10;++k) {
                dp[i][j][k].first=-1;
                dp[i][j][k].second=0;
            }
        }
    }
    while(t--) {
        int n;
        cin>>n;
        string l,r;
        cin>>l>>n;
        cin>>r;
        reverse(l.begin(),l.end());
        reverse(r.begin(),r.end());
        ll ans=0;
        for(int i=0;i<l.size();++i) {
            int j=i;
            while(j<l.size() && l[j]==l[i]) {
                ++j;
            }
            --j;
            i=j;
            ll dig=l[i]-'0';
            ans=(ans+((dig*____pow10[i])%mod))%mod;
        }
//        cout<<ans<<endl;
        ans=(ans+solve(r.size()-1,1,0,r).first)%mod;
        ans=(ans-solve(l.size()-1,1,0,l).first+mod)%mod;
        cout<<ans<<endl;
    }

    return 0;
}