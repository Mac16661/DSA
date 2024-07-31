class Solution {
public:
    int scoreOfString(string s) {
        int diff = 0;
        int sum = 0;
        int j=0;
        for(int i=1; i<s.size(); i++) {
            sum += abs(s[j]-s[i]);
            // cout<<abs(s[j]-s[i])<<" ";
            j++;
        }
        return sum;
    }
};