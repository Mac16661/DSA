class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        sort(nums.begin(), nums.end());

        for(int i=n-1; i>=2; i--) {
            if (nums[i] == 0) continue;
            int k = 0, l = i-1;

            while(k<l) {
                if(nums[k]+nums[l] > nums[i]) {
                    cnt+= (l-k);
                    l--;
                }else {
                    k++;
                }
            }
        }

        return cnt;
    }
};