class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& vis) {
        vis[node] = true;

        for(auto neig: graph[node]) {
            if(!vis[neig]) {
                dfs(neig, graph, vis);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if(m < n-1) return -1; // min n-1 edeges require to build a spanning tree
        
        vector<vector<int>> graph(n);
        for(auto edge:connections) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> vis(n, false);
        int comp = 0;
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                comp++;
                dfs(i, graph, vis);
            }
        }

        // Number of unvisited node > no of unplugged cables return -1 else return cnt (actually needed n-1 cables to make it a spanning tree)
        return comp-1;
    }
};