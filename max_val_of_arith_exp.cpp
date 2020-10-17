// Coursera Question - Algorithmic Toolbox
#include<bits/stdc++.h>
using namespace std;

long long dp[30][30];
long long dp2[30][30];
vector<long long> operators;
vector<long long> operands;

long long operate(long long a, long long b, long long op) {
    if(op == 0) {
        return a + b;
    }
    if(op == 1) {
        return a * b;
    }
    return a - b;
}

pair<long long, long long> solve(long long start, long long end) {
    // cout<<"At "<<start<<" "<<end<<endl;
    if(start == end) {
        long long res = operate(operands[start], operands[start + 1], operators[start]);
        // cout<<"Returning-1:"<<res<<endl;
        return {res, res};
    }
    if(start == end - 1) {
        long long res =  max(
            operate(operate(operands[start], operands[start + 1], operators[start]), 
                    operands[start + 2], operators[start + 1]),
            operate(operands[start], 
                    operate(operands[start + 1], operands[start + 2], operators[start + 1]),
                    operators[start]));
        long long res2 = min(
            operate(operate(operands[start], operands[start + 1], operators[start]), 
                    operands[start + 2], operators[start + 1]),
            operate(operands[start], 
                    operate(operands[start + 1], operands[start + 2], operators[start + 1]),
                    operators[start]));
        // cout<<"Returning-2:" << res<<" " << res2<<endl;
        return {res, res2};
    }
    if(dp[start][end] != -1) {
        // cout<<"Cache:"<<dp[start][end]<<" "<<dp2[start][end]<<endl;
        return {dp[start][end], dp2[start][end]};
    }
    pair<long long, long long> res = solve(start + 1, end);
    pair<long long, long long> tmp = solve(start, end - 1);
    long long mx = max(
        max(operate(operands[start], res.first, operators[start]),
        operate(tmp.first, operands[end + 1], operators[end])),
        max(operate(operands[start], res.second, operators[start]),
        operate(tmp.second, operands[end + 1], operators[end])));
    long long mn = min(
        min(operate(operands[start], res.first, operators[start]),
        operate(tmp.first, operands[end + 1], operators[end])),
        min(operate(operands[start], res.second, operators[start]),
        operate(tmp.second, operands[end + 1], operators[end])));
    for(long long i = start + 1; i < end; ++i) {
        pair<long long, long long> tmp1 = solve(start, i - 1);
        pair<long long, long long> tmp2 =  solve(i + 1, end);
        long long mx2 = max(
            max(operate(tmp1.first, tmp2.first, operators[i]),
            operate(tmp1.first, tmp2.second, operators[i])),
            max(operate(tmp1.second, tmp2.first, operators[i]),
            operate(tmp1.second, tmp2.second, operators[i])));
        long long mn2 = min(
            min(operate(tmp1.first, tmp2.first, operators[i]),
            operate(tmp1.first, tmp2.second, operators[i])),
            min(operate(tmp1.second, tmp2.first, operators[i]),
            operate(tmp1.second, tmp2.second, operators[i])));
        mx = max(mx, mx2);
        mn = min(mn, mn2);
    }
    // cout<<"Returning:" << mx<<" "<< mn<<endl;
    // cout<<start<<" "<<end<<":"<<res<<endl;
    dp[start][end] = mx;
    dp2[start][end] = mn;
    return {mx, mn};
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    string s;
    cin >> s;
    if(s.size() == 1) {
        cout<<s;
        return 0;
    }
    for(long long i = 1; i < s.size(); i+=2) {
        operands.push_back(s[i - 1]-'0');
        if(s[i] == '+') {
            operators.push_back(0);
        }
        else if(s[i] == '*') {
            operators.push_back(1);
        }
        else {
            operators.push_back(2);
        }
    }
    operands.push_back(s[s.size() - 1] - '0');
    // for(auto i:operands) cout<<i<<" ";
    // cout<<endl;
    memset(dp, -1 ,sizeof dp);
    memset(dp, -1, sizeof dp);
    cout << solve(0, operators.size() - 1).first;
}
