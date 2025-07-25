class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int maxi = 0;
        stack<int> st;

        for(int i=0; i<nums.size(); i++) {
           if(st.empty() || nums[st.top()] > nums[i]) {
                st.push(i);
           }
        }

        for(int i=nums.size()-1; i>=0; i--) {
            while(!st.empty() && nums[st.top()] <= nums[i]  ){
                maxi = max(maxi, i - st.top());
                st.pop();
            }
        }

        return maxi;
    }
};