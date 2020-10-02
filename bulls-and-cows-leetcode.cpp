// Bulls and Cows

class Solution {
public:
    string getHint(string secret, string guess) {
        string res;
        int bc = 0, cc = 0;
        vector<int> unma, unmb;
        for(int i=0;i<secret.length();i++) {
            if(secret[i] == guess[i]) {
                bc++;
            } else {
                unma.push_back(secret[i]-'0');
                unmb.push_back(guess[i]-'0');
            }
        }
        sort(unma.begin(), unma.end());
        sort(unmb.begin(), unmb.end());
        for(int i=0,j=0;i<unma.size() && j<unmb.size();) {
            if(unma[i] < unmb[j])
                i++;
            else if(unma[i] > unmb[j])
                j++;
            else
                cc++, i++, j++;
        }
        res += to_string(bc);
        res += "A";
        res += to_string(cc);
        res += "B";
        return res;
    }
};
