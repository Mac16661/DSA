class Solution {
public:
    int numberOfMatches(int n) {
        int cnt = 0;
        while(n!=1) {
            int match = n/2;
            n = n-match;
            cnt+= match;
        }
        return cnt;
    }
};