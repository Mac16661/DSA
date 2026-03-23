class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // int cnt=0;
        // int maxi = 0;

        // for(int i=1; i<nums.size(); i++) {
        //     if(nums[i-1] == nums[i] && nums[i] == 1){
        //         cnt++;
        //     }else{
        //         cnt = 0;
        //     }

        //     maxi = max(maxi, cnt);
        // }

        // return maxi+1;

        int r=0;
        int count =0;
        int maxi = INT_MIN;

        while(r<nums.size()) {
            if(nums[r] == 0){
                count = 0;
            }else{
                count++;
            }

            maxi = max(maxi, count);
            r++;

        }

        return maxi;
    }
};