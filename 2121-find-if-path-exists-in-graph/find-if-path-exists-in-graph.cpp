class Solution {
public:
    void dfs(int node, vector<vector<int>> graph, vector<int>& visited, int dest, bool &reachable) {
        visited[node] = 1;

        if(node == dest) {
            reachable = true;
        }

        for(auto neigh : graph[node]) {
            if(visited[neigh] == -1) dfs(neigh, graph, visited, dest, reachable);
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        // Creating graph
        vector<vector<int>> graph(n);

        for(auto edge: edges) {
            int u = edge[0]; 
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> visited(n, 0);
        queue<int> q;
        q.push(source);
        visited[source] = 1;

        while (!q.empty()) {
            int node = q.front(); q.pop();
            if (node == destination) return true;
            for (int neigh : graph[node]) {
                if (!visited[neigh]) {
                    visited[neigh] = 1;
                    q.push(neigh);
                }
            }
        }
        return false;
    }
};