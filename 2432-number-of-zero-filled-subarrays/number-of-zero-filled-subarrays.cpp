class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        /*
            If you have given a array of size n you can easily find out the number of subarray using formula int subarr = ( n ) * ( n + 1 ) / 2 ;
        */

        long long total = 0;     // total number of zero-filled subarrays
        int count = 0;           // current streak length

        for (int x : nums) {
            if (x == 0) {
                count++;
            } else {
                if (count > 0) {
                    total += 1LL * count * (count + 1) / 2;
                    count = 0;
                }
            }
        }

    // handle if the array ends with zeros
        if (count > 0) {
            total += 1LL * count * (count + 1) / 2;
        }

        return total;
    }
};