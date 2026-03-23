class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& t, vector<int>& target) {
        vector<int> ans(3,0);
        for(int i=0; i<t.size(); i++) {
            if(t[i][0] <= target[0] && t[i][1] <= target[1] && t[i][2] <= target[2]) {
                ans[0] = max(t[i][0], ans[0]);
                ans[1] = max(t[i][1], ans[1]);
                ans[2] = max(t[i][2], ans[2]);
            }
        }

        // cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;

        bool f = target[0] == ans[0];
        bool s = target[1] == ans[1];
        bool th = target[2] == ans[2];

        if(f && s&& th) return true;
        return false;   
    }
};