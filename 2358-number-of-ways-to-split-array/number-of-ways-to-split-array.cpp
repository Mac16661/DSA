class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long> prefix(n);

        prefix[0] = nums[0];
        for(int i=1; i<n; i++) {
            prefix[i] = nums[i] + prefix[i-1];
        }   

        int count = 0;
        for(int i=0; i<n-1; i++) {
            long left = prefix[i];
            long right = prefix[n-1] - prefix[i];
            if(left>=right) count++;
        }

        return count;
    }
};