class Solution {
public:
    // time nlogn
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        if(n <= 1) return nums;

        sort(nums.begin(), nums.end());
        int cnt = 0;
        
        vector<int> ans;

        for(int i=1; i<nums.size(); i++) {
            if(nums[i-1] == nums[i]) cnt++;
            else{
                if((cnt+1) > n/3) {
                    ans.push_back(nums[i-1]);
                }
                cnt = 0;
            }
        }

        // for the last element
        if((cnt+1) > n/3) {
            ans.push_back(nums[n-1]);
        }

        return ans;
    }
};