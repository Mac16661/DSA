class Solution {
public:
    bool sqrtCust(int num) {
        long low = 0, high = num;

        while(low<=high) {
            long long mid = (low+high)/2;

            if(mid*mid == num) {
                return true;
                // cout<<mid;
            }else if(mid*mid < num) {
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return false;
    } 
    bool isPerfectSquare(int num) {
        if(num == 1) return true;
        // cout<<sqrtCust(num);

        return sqrtCust(num);
    }
};