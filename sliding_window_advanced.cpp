/*
 * Problem: https://www.hackerearth.com/practice/algorithms/searching/ternary-search/practice-problems/algorithm/download-file-b0fe3520/
 * Approach Used : Sliding Window
 * Problem TC Weak when moving from end
 * According to editorial, at least first or last block must be completely filled.
 * For further references use Hassan Jaddouh's submission as reference
 */
#include <bits/stdc++.h>

#define mkp(a, b) make_pair(a,b)
using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
typedef long l;

bool comp(pii a, pii b) {
    //for handling fractional comparisons
    //typecasting was very important here
    return (l) a.first * (l) b.second < (l) b.first * (l) a.second;
}

pii solve(pii min_duration, vector<pii> a, int n, int s) {
    //For Left to Right
    vector<pii> segments;
    for (int i = 0; i < n; ++i) {
        if (i != 0) {
            segments.emplace_back(a[i].first - a[i - 1].first, a[i - 1].second);
        }
    }
    segments.emplace_back(s, a[n - 1].second);
    l sum_so_far = 0;
    int trav = 0;
    for (int i = 0; i < n; ++i) {
        sum_so_far += segments[i].first * segments[i].second;
        trav++;
        if (sum_so_far >= s) {
            // cout<<"Sum so far:"<<sum_so_far<<endl;
            l psum = sum_so_far - segments[i].first * segments[i].second;
            // cout<<"psum"<<psum<<endl;
            int rem = (int) floor((ld) (s - psum) / (ld) segments[i].second);
            l res = s - (psum + rem * segments[i].second);
            int num, den;
            num = a[i].first - a[i - trav + 1].first + rem;
            den = 1;
            if (res != 0) {
                num = (segments[i].second * num + res);
                den = segments[i].second;
            }
            // cout<<"res:"<<res<<endl;
            // cout<<"fraction:"<<num<<"/"<<den<<endl;
            // cout<<i<<":"<<rem<<endl;
            // cout<<"curr_duration:"<<a[i].first-a[i-trav+1].first+rem<<endl;
            if (comp(mkp(num, den), min_duration)) {
                min_duration.first = num;
                min_duration.second = den;
            }
            // cout<<"updated duration:"<<min_duration<<endl;
            sum_so_far -= segments[i - trav + 1].first * segments[i - trav + 1].second;
            trav--;
            if (trav == 0) {
                // cout<<"pass\n";
                continue;
            }
            sum_so_far -= segments[i].first * segments[i].second;
            trav--;
            i--;
            // cout<<i<<" "<<trav<<endl;
        }
    }
    segments.pop_back();
    return min_duration;
}

pii solve2(pii min_duration, vector<pii> a, int n, int s) {
    //For Right to Left
    //Separate Function Used because here we do not append s residual length at segments vector's end
    vector<pii> segments;
    for (int i = 0; i < n; ++i) {
        if (i != 0) {
            segments.emplace_back(a[i].first - a[i - 1].first, a[i - 1].second);
        }
    }
    // cout<<segments.size()<<endl;
    l sum_so_far = 0;
    int trav = 0;
    for (int i = 0; i < n - 1; ++i) {
        sum_so_far += segments[i].first * segments[i].second;
        trav++;
        if (sum_so_far >= s) {
            // cout<<"Sum so far:"<<sum_so_far<<endl;
            l psum = sum_so_far - segments[i].first * segments[i].second;
            // cout<<"psum"<<psum<<endl;
            int rem = (int) floor((ld) (s - psum) / (ld) segments[i].second);
            l res = s - (psum + rem * segments[i].second);
            int num, den;
            num = a[i].first - a[i - trav + 1].first + rem;
            den = 1;
            if (res != 0) {
                num = (segments[i].second * num + res);
                den = segments[i].second;
            }
            // cout<<"res:"<<res<<endl;
            // cout<<"fraction:"<<num<<"/"<<den<<endl;
            // cout<<i<<":"<<rem<<endl;
            // cout<<"curr_duration:"<<a[i].first-a[i-trav+1].first+rem<<endl;
            if (comp(mkp(num, den), min_duration)) {
                min_duration.first = num;
                min_duration.second = den;
            }
            // cout<<"updated duration:"<<min_duration<<endl;
            sum_so_far -= segments[i - trav + 1].first * segments[i - trav + 1].second;
            trav--;
            if (trav == 0) {
                // cout<<"pass\n";
                continue;
            }
            sum_so_far -= segments[i].first * segments[i].second;
            trav--;
            i--;
        }
    }
    segments.pop_back();
    return min_duration;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, s;
    cin >> n >> s;
    vector<pii> a(n), b, segments;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    pii min_duration = mkp(INT_MAX, 1);
    pii tmp = solve(min_duration, a, n, s);
    for (int i = 0; i < n; ++i) {
        //At 0 we can have any random as second value. I subtracted a[i].first from a[n-1].first to get reverse series.
        b.emplace_back(a[n - 1].first - a[i].first, ((i > 0) ? a[i - 1].second : s));
    }
    // cout<<b.size()-1<<endl;
    reverse(b.begin(), b.end());
    pii tmp2 = solve2(tmp, b, n, s);
    if (comp(tmp, tmp2)) {
        cout << tmp.first / __gcd(tmp.first, tmp.second) << "/" << tmp.second / __gcd(tmp.first, tmp.second);
    } else {
        cout << tmp2.first / __gcd(tmp2.first, tmp2.second) << "/" << tmp2.second / __gcd(tmp2.first, tmp2.second);
    }
}