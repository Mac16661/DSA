class Solution {
public:
    int titleToNumber(string col) {
        int n = col.size()-1;
        int cnt = 0;
        int ans = 0;

        while (n >= 0) {
            ans += (col[n] - 'A' + 1) * pow(26, cnt);
            cnt++;
            n--;
        }

        return ans;
    }
};