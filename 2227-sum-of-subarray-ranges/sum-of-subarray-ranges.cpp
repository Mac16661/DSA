#define ll long long
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        ll sum = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int minVal = INT_MAX;
            int maxVal = INT_MIN;

            for(int j = i; j < n; j++) {  // Fix: Use j < n, increment j
                minVal = min(nums[j], minVal);
                maxVal = max(nums[j], maxVal);
                sum += (maxVal - minVal);  // Fix: Use maxVal - minVal
            }
        }

        return sum;
    }
};
