class Solution {
public:
    // time nlogn
    // vector<int> majorityElement(vector<int>& nums) {
    //     int n = nums.size();

    //     if(n <= 1) return nums;

    //     sort(nums.begin(), nums.end());
    //     int cnt = 0;
        
    //     vector<int> ans;

    //     for(int i=1; i<nums.size(); i++) {
    //         if(nums[i-1] == nums[i]) cnt++;
    //         else{
    //             if((cnt+1) > n/3) {
    //                 ans.push_back(nums[i-1]);
    //             }
    //             cnt = 0;
    //         }
    //     }

    //     // for the last element
    //     if((cnt+1) > n/3) {
    //         ans.push_back(nums[n-1]);
    //     }

    //     return ans;
    // }

    // liner time complexity
    vector<int> majorityElement(vector<int>& nums) {
        int ele1 = -1, ele2 = -1;
        int cnt1 = 0, cnt2 = 0;
        int setE2 = 0;

        for(int i=0; i<nums.size(); i++) {
            // For element 1
            if(cnt1 == 0 && nums[i] != ele2){
                cnt1 = 1;
                ele1 = nums[i];
            }else if(nums[i] == ele1) cnt1++;
            // For element 2
            else if(cnt2 == 0 && nums[i] != ele1) {
                cnt2 = 1;
                ele2 = nums[i];
            }else if(nums[i] == ele2) cnt2++;
            else{
                cnt1--;cnt2--;
            }
        }

        vector<int> ans;
        // if(ele2 != -1 || ele1 != -1) {
            cnt2 = 0;
            cnt1 = 0;
            for(auto i:nums) {
                if(i == ele2) cnt2++; 
                else if(i == ele1) cnt1++;
            }

            if(cnt2 > nums.size()/3) ans.push_back(ele2);
            if(cnt1 > nums.size()/3) ans.push_back(ele1);
        // }

        return ans;
    }
};