class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOnce = INT_MIN;
        int curr = 0;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 0) {
                curr = 0;
            }else{
                curr++;
            }
            maxOnce = max(curr, maxOnce);
        }

        return maxOnce;
    }
};