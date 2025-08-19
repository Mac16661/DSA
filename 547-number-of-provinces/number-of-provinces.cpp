class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& vis) {
        vis[node]=1;
        // push node to ds if need to return the traversal

        for(int i = 0; i < isConnected[0].size(); i++) {
            if(isConnected[node][i] == 1 && !vis[i]) {
                dfs(i, isConnected, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0); // 1 based indexing
        int cnt =0; // no of connected components

        for(int i=0; i<n; i++) {
            if(!vis[i]) { // when vis[i] == 0
                dfs(i, isConnected, vis);
                cnt++;

                // for(auto i:vis) {
                //     cout<<i<<" ";
                // }
                // cout<<" -> "<<i<<endl;
            } 
        }

        return cnt;
    }
};