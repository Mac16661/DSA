class Solution {
public:
    bool dfs(vector<vector<int>>&graph,vector<int>&vis,int i)
    {
        if(vis[i]==1) return false;
        if(vis[i]==2) return true;
        vis[i] = 1;
        for(auto it : graph[i])
            if(!dfs(graph,vis,it)) return false;
        vis[i] = 2;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>ans;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
            if(dfs(graph,vis,i)) ans.push_back(i);
        return ans;
    }
};