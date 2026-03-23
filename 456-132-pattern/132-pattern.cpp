class Solution {
public:
    bool find132pattern(vector<int>& nums) {
    int n = nums.size();
    stack<int> st;
    int s3 = INT_MIN;

    for (int i = n - 1; i >= 0; --i) {
        if (nums[i] < s3) return true;
        while (!st.empty() && st.top() < nums[i]) {
            s3 = st.top(); st.pop();
        }
        st.push(nums[i]);
    }
    return false;
}
};