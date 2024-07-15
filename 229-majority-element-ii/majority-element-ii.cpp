class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        int ele1=-1, ele2=-1;

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

         vector<int> result;
        int threshold = nums.size() / 3; // Threshold for majority element

        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (ele1 == nums[i]) {
                cnt1++;
            } else if (ele2 == nums[i]) {
                cnt2++;
            }
        }

        if(cnt1 > threshold) result.push_back(ele1);
        if(cnt2 > threshold) result.push_back(ele2);

        return result;
    }
};