class Solution {
public:
    int mini = INT_MAX;

    void dfs(int node, unordered_map<int, vector<pair<int, int>>>& graph, vector<int>& visited) {
        visited[node] = 1;

        for (auto &[neigh, weight] : graph[node]) {
            mini = min(mini, weight); // update with every edge in component
            if (visited[neigh] == 0) {
                dfs(neigh, graph, visited);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> graph;

        for (auto &it : roads) {
            int u = it[0], v = it[1], w = it[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        vector<int> visited(n + 1, 0);

        dfs(1, graph, visited);

        return mini;
    }
};
