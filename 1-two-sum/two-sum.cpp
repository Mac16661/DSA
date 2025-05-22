class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        // mpp[0] = 1;
        vector<int> ans;

        for(int i=0; i<nums.size(); i++) {
            // if(nums[i] <= target) {
                int remaining = target - nums[i];
                if(mpp.find(remaining) != mpp.end()) {
                    ans.push_back(mpp[remaining]);
                    ans.push_back(i);

                    return ans;
                }
            // }

            mpp[nums[i]] = i;
        }

        return ans;
    }
};