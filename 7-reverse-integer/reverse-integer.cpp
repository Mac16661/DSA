class Solution {
public:
    int reverse(int x) {
        long long ans = 1/10;

        while(x) {
            ans = ans * 10;
            ans += x%10;
            x = x/10;
        }

        if(ans < numeric_limits<int>::min() || ans > numeric_limits<int>::max()) return 0;
        return int(ans);
    }
};