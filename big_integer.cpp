#include <bits/stdc++.h>
#define mod 1000000007
#define mkp(a,b) make_pair(a,b)
using namespace std;
typedef long l;
typedef long double ld;
typedef pair<l,l> pll;
typedef pair<int,int> pii;
class BigInteger
{
private:
    vector<int> v;
    void pad(BigInteger &b,int sz)
    {
        while(b.size()<sz)
        {
            b.v.emplace_back(0);
        }
    }
    int size()
    {
        return v.size();
    }
public:
    BigInteger()= default;
    explicit BigInteger(string s)
    {
        for(int i=s.size()-1;i>=0;--i)
        {
            v.emplace_back(s[i]-'0');
        }
    }
    BigInteger operator +(BigInteger b)
    {
        BigInteger res("");
        BigInteger tmp=(*this);
        pad(b,max(b.size(),tmp.size()));
        pad(tmp,max(b.size(),tmp.size()));
//        cout<<tmp.to_string()<<" "<<b.to_string()<<endl;
        int c=0;
        for(int i=0;i<b.size();++i)
        {
            int sum=b.v[i]+v[i]+c;
            if(sum<10)
            {
                res.v.emplace_back(sum);
                c=0;
            }
            else
            {
                res.v.emplace_back(sum%10);
                c=sum/10;
            }
        }
        if(c!=0)
        {
            res.v.emplace_back(c);
        }
        return res;
    }
    BigInteger operator *(BigInteger b)
    {
        if(b.size()>this->size())
        {
            return b*(*this);
        }
//        cout<<b.to_string()<<endl;
        if(b.size()==1)
        {
            BigInteger final;
            int c=0;
            for(int i=0;i<this->size();++i)
            {
                int store=b.v[0]*v[i]+c;
                if(store<10)
                {
                    c=0;
                    final.v.emplace_back(store);
                }
                else
                {
                    final.v.emplace_back(store%10);
                    c=store/10;
                }
            }
            if(c!=0)
            {
//                cout<<"padded";
                final.v.emplace_back(c);
            }
//            cout<<final.to_string()<<endl;
            return final;
        }
        BigInteger res[b.size()];
        int max_sz=0;
        for(int i=0;i<b.size();++i)
        {
            string _;
            _+=(char)(b.v[i]+'0');
            BigInteger tmp(_);
//            cout<<tmp.to_string()<<endl;
            res[i]=tmp*(*this);
//            cout<<res[i].to_string()<<endl;
//            break;
            for(int j=0;j<i;++j)
            {
                res[i].v.insert(res[i].v.begin(),0);
            }
            max_sz=max(max_sz,res[i].size());
        }
        BigInteger final("");
        final.v=vector<int>(max_sz);
        for(int i=0;i<b.size();++i)
        {
            final=final+res[i];
        }
        return final;
    }
    string to_string()
    {
        string s;
        for(int i=this->size()-1;i>=0;--i)
        {
            s+=(char)(v[i]+'0');
        }
        return s;
    }
};
string itos(int num)
{
    string s;
    while(num!=0)
    {
        s+=(char)(num%10+'0');
        num/=10;
    }
    reverse(s.begin(),s.end());
    return s;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    BigInteger fact[100];
    fact[0]=BigInteger("1");
    for(int i=1;i<100;++i)
    {
//        cout<<itos(i)<<endl;
//        cout<<(BigInteger("11")*BigInteger("12")).to_string();
        BigInteger tmp(itos(i+1));
//        cout<<tmp.to_string()<<endl;
        fact[i]=(fact[i-1]*tmp);
//        cout<<fact[i].to_string()<<endl;
//        break;
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<fact[n-1].to_string()<<endl;
    }
    return 0;
}