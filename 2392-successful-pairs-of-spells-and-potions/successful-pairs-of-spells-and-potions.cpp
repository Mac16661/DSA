class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        vector<int> ans(n);
        
        sort(potions.begin(), potions.end());

        for(int i=0; i<n; i++) {
            long long need = (success + spells[i] - 1) / spells[i]; // ceil(success / spells[i])
            
            // Find first potion >= need
            auto it = lower_bound(potions.begin(), potions.end(), need);
            int count = potions.end() - it;
            
            ans[i] = count;
        }

        return ans;
    }
};