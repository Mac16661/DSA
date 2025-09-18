class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int l = 0, r = n-1;
        int i = r;
        while(l<=r) {
            if(i<0) break;

            int leftSide = nums[l] * nums[l];
            int rightSide = nums[r] * nums[r];

            if(leftSide > rightSide) {
                ans[i] = leftSide;
                // cout<<leftSide<<endl;
                l++;
            }else{
                ans[i] = rightSide;
                // cout<<rightSide<<endl;
                r--;
            }
            i--;
            // cout<< leftSide<< "  "<<rightSide<<" - > "<<ans[i]<<" "<<endl;
        }

        return ans;
    }
};