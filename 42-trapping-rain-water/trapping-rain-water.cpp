class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(height), right(height); // prefix and suffix sum
        int ans = 0;

        for(int i=1; i<n; i++) {
            left[i] = max(left[i], left[i-1]);
        }
        for(int i=n-2; i>=0; i--) {
            right[i] = max(right[i], right[i+1]);
        }

        // for(auto i : left) cout<<i;
        // cout<<endl;
        // for(auto i : right) cout<<i;

        for(int i=0; i<n; i++) {
            int water = min(left[i], right[i]);
            if(water >= height[i]) ans += water - height[i];
        }
        return ans;
    }
};