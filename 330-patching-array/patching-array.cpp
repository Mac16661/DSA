class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long maxReach = 0;  
        int patches = 0;
        int i = 0;

        while (maxReach < n) {
            if (i < nums.size() && nums[i] <= maxReach + 1) {
                maxReach += nums[i];  
                i++;
            } else {
                // Patch with maxReach + 1
                maxReach += maxReach + 1;
                patches++;
            }
        }

        return patches;
    }
};