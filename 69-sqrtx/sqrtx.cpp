class Solution {
public:
    int mySqrt(int x) {
        if(x<=1) return x;

        long low = 1, high = x;
        long long ans = 1;

        while(low <= high) {
            long long mid = (low+high)/2;

            if(mid*mid <= x*1ll) {
                ans = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }

        return ans;
    }
};