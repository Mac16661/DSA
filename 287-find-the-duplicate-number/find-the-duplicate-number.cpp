class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Brute forece -> use nested loops to determin the duplicates

        // Betrer  - > use a set to determin if there is nay duplicate and return
        // int n=nums.size();
        // unordered_set<int> st;

        // for(int i=0; i<n; i++) {
        //     if(st.count(nums[i])) return nums[i];
        //     st.insert(nums[i]);
        // }

        // return -1;

        // Optimal -> without modifing the array and constant extra space
        // TODO: Fast and slow pointer apprach
        // Findig the intersection point
        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);

        // Phase 2: Find entranc to the cycle
        slow = nums[0];

        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};