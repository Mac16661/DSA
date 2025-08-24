class Solution {
    vector<vector<int>> paths;
public:
    void dfs(int node, vector<vector<int>>& graph, vector<int>& path) {
        if(node == graph.size()-1) {
            paths.push_back(path);
            return;
        }

        for(auto i: graph[node]){
            path.push_back(i);
            dfs(i, graph, path);
            path.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> path;
        path.push_back(0);

        dfs(0, graph, path);
        return paths;
    }
};