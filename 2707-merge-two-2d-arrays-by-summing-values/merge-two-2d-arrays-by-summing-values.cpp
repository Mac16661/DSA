class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        int i = 0, j = 0, n = nums1.size(), m = nums2.size();
        
        while (i < n && j < m) {
            if (nums1[i][0] < nums2[j][0]) {
                add(ans, nums1[i]);
                i++;
            } else if (nums1[i][0] > nums2[j][0]) {
                add(ans, nums2[j]);
                j++;
            } else {
                add(ans, {nums1[i][0], nums1[i][1] + nums2[j][1]});
                i++; j++;
            }
        }

        // Add remaining elements
        while (i < n) add(ans, nums1[i++]);
        while (j < m) add(ans, nums2[j++]);

        return ans;
    }

    void add(vector<vector<int>>& ans, const vector<int>& v) {
        if (!ans.empty() && ans.back()[0] == v[0]) {
            ans.back()[1] += v[1];
        } else {
            ans.push_back(v);
        }
    }
};
