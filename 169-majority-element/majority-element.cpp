class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int Element;

        for(int i=0; i<nums.size(); i++) {
            if(count == 0) {
                count=1;
                Element = nums[i];
            }else if(Element == nums[i]){
                count++;
            }else {
                count--;
            }
        }

        return Element;
    }
};