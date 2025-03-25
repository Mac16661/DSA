class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i=0; i<nums1.size(); i++) {
            int val = nums1[i];
            int set = -1;
            for(int j=0; j< nums2.size(); j++) {
                if(val == nums2[j]){ 
                    set=1;
                }

                if(set==1 && nums2[j] > val){
                    ans.push_back(nums2[j]);
                    set=-1;
                    continue;
                }
            }
            if(set==1){
                ans.push_back(-1);
                set=-1;
            }
        }

        return ans;
    }
};