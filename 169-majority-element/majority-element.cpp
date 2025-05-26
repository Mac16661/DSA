class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // voting algo
        int count = 0;
        int element = -1;

        for(auto i: nums) {
            if(count == 0) {
                element = i;
            }

            if(i == element) count++;
            else count--;
        }

        return element;
    }
};