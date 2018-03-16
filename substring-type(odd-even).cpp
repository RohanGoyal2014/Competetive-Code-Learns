/*
 You are given an array A of N positive integer values. A subarray of this array is called Odd-Even subarray if the number of odd integers in this subarray is equal to the number  of even integers in this subarray.

Find the number of Odd-Even subarrays for the given array.

Input Format:
The input consists of two lines.

First line denotes N - size of array.
Second line contains N space separated positive integers denoting the elements of array A.

Output Format:
Print a single integer, denoting the number of Odd-Even subarrays for the given array.

Logic Used: for subarray (i,j):
 even[i]-even[j-1]=odd[i]-odd[j-1]
 this implies that
 even[i]-odd[i]=even[j-1]-odd[j-1]
 We store default value of 1 for 0
 then we proceed forward as saving evencount-oddcount and then applying the formula
 */
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long n;
    cin>>n;
    long long a[n];
    map<long long,long long> mp;
    mp[0]=1;
    long long odd_count=0,even_count=0;
    for(long i=0;i<n;++i)
    {
        cin>>a[i];
        if(a[i]%2==0)
        {
            odd_count++;
        }
        else
        {
            even_count++;
        }
        if(mp.find(odd_count-even_count)==mp.end())
        {
            mp[odd_count-even_count]=1;
        }
        else
        {
            mp[odd_count-even_count]++;
        }
    }
    long long sum=0;
    for(auto i=mp.begin();i!=mp.end();++i)
    {
        long long val=i->second;
        sum+=((val-1)*val)/2;
    }
    cout<<sum<<endl;
}