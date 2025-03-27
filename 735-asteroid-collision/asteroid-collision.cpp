class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int> st;

        for(auto a : arr) {
            bool destroyed = false;  // Flag to check if asteroid is destroyed

            while (!st.empty() && st.top() > 0 && a < 0) {
                if (st.top() < abs(a)) {
                    st.pop();  // Destroy the right-moving asteroid
                    continue;  // Keep checking previous asteroids
                } else if (st.top() == abs(a)) {
                    st.pop();  // Both asteroids destroy each other
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;  // The current asteroid is destroyed
                    break;
                }
            }

            if (!destroyed) {
                st.push(a);  // Only push if not destroyed
            }
        }

        vector<int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};
