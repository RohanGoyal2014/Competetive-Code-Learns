/*
 * Longest Prefix that is also a suffix
 * (Used in KMP Algorithm for pattern matching)
 * Link of problem: https://codeforces.com/contest/1138/problem/D
 * */

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define mkp(a,b) make_pair(a,b)
#define PI 3.14159265359
#define MAXN 5000005
#define mset(arr,val) memset(arr,val,sizeof arr)
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

bool comp(int a[],int b[]) {
    return (a[0]>=b[0]) && (a[1]>=b[1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    FILE_READ;
//    FILE_WRITE;

    string s,t;
    cin>>s>>t;
    int a1[2]={0},a2[2]={0};
    for(int i=0;i<s.size();++i) {
        a1[s[i]-'0']++;
    }
    for(int i=0;i<t.size();++i) {
        a2[t[i]-'0']++;
    }
    if(!comp(a1,a2)) {
        cout<<s;
        return 0;
    }
    cout<<t;

//    cout<<buff<<endl;
    int _[2]={0};
    int len=0,j=1;
    int n=t.size();
    int lps[t.size()]={0};
    while(j<n) {
        if(t[j]==t[len]) {
            ++len;
            lps[j]=len;
            ++j;
        } else {
            if(len==0) {
                lps[j]=0;
                ++j;
            } else {
                len=lps[len-1];
            }
        }

    }
    int res=lps[n-1];
    string suff;
    for(int i=res;i<t.size();++i) {
        suff+=t[i];
        _[t[i]-'0']++;
    }

    a1[0]-=a2[0];
    a1[1]-=a2[1];
//    cout<<a1[0]<<" "<<a1[1]<<endl;
//    cout<<endl<<_[0]<<" "<<_[1]<<endl;
    while(comp(a1,_)) {
        cout<<suff;
        a1[0]-=_[0];
        a1[1]-=_[1];
    }
    while(a1[0]--) {
        cout<<0;
    }
    while(a1[1]--) {
        cout<<1;
    }



    return 0;
}
