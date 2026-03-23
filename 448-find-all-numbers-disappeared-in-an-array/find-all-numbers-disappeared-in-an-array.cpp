class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        // optimal
        for(auto x:nums) {
            int idx = abs(x) - 1;  

            // Marking if not already marked
            if(nums[idx] > 0) {
                nums[idx] = -abs(nums[idx]);
            }
        }
        // Nums[i] is telling for which index it is missing, so naturally we need to do + 1 to get the actual value cosidering everything will be int the sorted order
        // now just put all the +ve num in ans arr
        vector<int> ans;
        for(int i=0; i<n; i++) {
            if(nums[i] > 0)
                ans.push_back(i + 1);   
        }

        return ans;
    }
};