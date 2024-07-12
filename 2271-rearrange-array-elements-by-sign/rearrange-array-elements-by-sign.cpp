class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int i = 0;
        int pos = 0;
        int neg = 1;

        while(i < nums.size()) {
            if(nums[i] >= 0) {
                // if(pos < nums.size())
                {
                    ans[pos] = nums[i];
                    pos += 2;
                }
            }else{
                // if(neg < nums.size())
                {
                    ans[neg] = nums[i];
                    neg += 2;
                }
            }
            i++;
        }

        return ans;
    }
};