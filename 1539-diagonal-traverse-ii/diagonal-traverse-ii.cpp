class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        // Map diagonal index (i + j) -> list of values
        unordered_map<int, vector<int>> diag;
        int maxKey = 0;

        for (int i = 0; i < (int)nums.size(); ++i) {
            for (int j = 0; j < (int)nums[i].size(); ++j) {
                int key = i + j;
                diag[key].push_back(nums[i][j]);
                if (key > maxKey) maxKey = key;
            }
        }

        vector<int> ans;
        ans.reserve(100000); // optional pre‑reserve

        // For each diagonal, traverse from bottom to top
        for (int k = 0; k <= maxKey; ++k) {
            auto &v = diag[k];
            // we inserted rows top→bottom, but we must output bottom→top
            for (int idx = (int)v.size() - 1; idx >= 0; --idx) {
                ans.push_back(v[idx]);
            }
        }
        return ans;
    }
};
