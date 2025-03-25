class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        stack<int> st;

        for(int i = nums2.size()-1; i>=0; i--) {
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            
            if(!st.empty()) {
                mp[nums2[i]] = st.top();
            }else{
                mp[nums2[i]] = -1;
            }

            st.push(nums2[i]);

        }

        for(int i=0; i<nums1.size(); i++) {
            int val = nums1[i];
            nums1[i]=mp[val];
        }
        return nums1;
    }
};