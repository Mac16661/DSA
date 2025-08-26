class Solution {
public:
    // Bfs with Bipartite check
    bool bfs(int node, vector<vector<int>>& graph, vector<int>& visited) {
        queue<int> q;
        q.push(node);
        visited[node] = 0; // start color

        while (!q.empty()) {
            int front = q.front();
            q.pop();

            for (auto it : graph[front]) {
                if (visited[it] == -1) {
                    visited[it] = !visited[front]; // opposite color
                    q.push(it); 
                }
                // TODO: Main login
                else if (visited[it] == visited[front]) {
                    return false; // same color on adjacent nodes not bipartite
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n,-1);

        for(int i=0; i<n; i++) {
            if(visited[i] == -1) {
                if(!bfs(i, graph, visited)) return false;
            }
        }

        return true;
    }
};