/*
Given below pattern of license plates (Pattern only, not the actual list of license plates), Find the nth license plate
All license plates no are of size 5 chars
Eg, if n is 3, ans is - 00002

00000
00001
00002
........
........
99999
0000A
0001A
0002A
........
.........
9999A
0000B
0001B
0002B
.........
.........
9999B
0000C
........
........
9999Z
000AA
001AA
.........
.........
999AA
000AB
..........
..........
999ZZ
00AAA
........
........
ZZZZZ


*/

#include<bits/stdc++.h>
using namespace std;
int getPower(int num, int k) {
    int ans = 1;
    while(k--) {
        ans *= num;
    }
    return ans;
}

string buffer(string s, int len) {
    return string(len - s.size(), '0') + s;
}

string hexadecimal(int val, int len) {
    if(len == 0) return "";
    int powerRest = getPower(26, len - 1);
    // cout << powerRest << endl;
    for(int j = 0; j < 26; ++j) {
        if((j + 1) * powerRest >= val) {
            return string(1, 'A' + j) + hexadecimal(val - j * powerRest, len - 1);
        }
    }
    throw "SOMETHING IS WRONG";
}

string getNthString(int n) {
    if(n <= 1000000) return buffer(to_string(n - 1), 6);
    int dec = 100000;
    int hex = 26;
    n -= 1000000;
    int size = 1;
    while(true) {
        if(n <= hex * dec) {
            break;
        }
        else {
            ++size;
            n -= hex * dec;
            hex *= 26;
            dec /= 10;
        }
    }
    int start = 1;
    int end = hex;
    int last = -1;
    while(start <= end) {
        int mid = start + (end - start)/2;
        if(mid * dec >= n) {
            last = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    string hexStr = hexadecimal(last, size);
    reverse(hexStr.begin(), hexStr.end());
    start = 1;
    int rem = (last - 1) * dec;
    n -= rem;
    // end = 
    return buffer(to_string(n - 1), 6 - size) + hexStr;
}
int main() {
    int n;
    cin >> n;
    cout << getNthString(n);
}
