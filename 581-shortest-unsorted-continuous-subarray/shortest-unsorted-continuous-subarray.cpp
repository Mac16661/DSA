class Solution {
public:
    vector<int> NSE(vector<int>& nums) {
        int n = nums.size();
        vector<int> nse(n, INT_MAX);
        stack<int> st;

        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && st.top() >= nums[i]){
                st.pop();
            }
            
            if(!st.empty()) nse[i] = st.top();

            st.push(nums[i]); 
        }

        return nse;
    }

    vector<int> PGE(vector<int>& nums) {
        int n = nums.size();
        vector<int> pge(n, INT_MIN);
        stack<int> st;

        for(int i=0; i<n; i++) {
            while(!st.empty() && st.top() <= nums[i]) st.pop();

            if(!st.empty()) pge[i] = st.top();

            st.push(nums[i]);
        }

        return pge;
    }

    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> nse = NSE(nums);
        vector<int> pge = PGE(nums);

        int first_idx = -1;

        for(int i=0; i<nums.size(); i++) {
            if(nse[i] != INT_MAX && nse[i] != nums[i]){
                first_idx = i;
                break;
            }
        }


        int sec_idx = -1;

        for(int i=nums.size()-1; i>=0; i--) {
            if(pge[i] != INT_MIN && pge[i] != nums[i]){
                sec_idx = i;
                break;
            }
        }

        if(first_idx != -1 && sec_idx != -1 && first_idx <= sec_idx){
            return sec_idx - first_idx + 1;
        }

        return 0;
    }
};