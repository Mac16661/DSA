class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // Brute O(k * n)
        // int n = nums.size();
        // k = k % n; // if it is greater then n it will wrap around

        // for (int i=0; i<k; i++) {
        //     int last = nums[n-1];
        //     for (int j = n-1; j > 0; j--) {
        //         nums[j] = nums[j-1];
        //     }

        //     nums[0] = last;
        // }

        // Optimal O(3n)
        int n = nums.size();
        k %= n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};