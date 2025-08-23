class Solution {
public:
    bool dfs(int src, int dest, vector<vector<int>>& graph, vector<bool>& vis) {
        if(src==dest) return true;
        bool found = false;

        vis[src] = true;

        for(auto it: graph[src]) {
            if(it == dest) return true;
            if(!vis[it]) {
                vis[it] = true;
                found = found || dfs(it, dest, graph, vis);
            }
        }
        return found || false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination) return true;
        
        // Use adjacency list - O(V + E) space and time
        vector<vector<int>> graph(n);
        for(const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        visited[source] = true;
        return dfs(source, destination, graph, visited);

        
        // vector<bool> visited(n, false);
        // queue<int> q;
        // visited[source] = true;
        // q.push(source);
        
        // while(!q.empty()) {
        //     int node = q.front();
        //     q.pop();
            
        //     // Only iterate through actual neighbors (not all n nodes)
        //     for(int neighbor : graph[node]) {
        //         if(neighbor == destination) return true;
                
        //         if(!visited[neighbor]) {
        //             visited[neighbor] = true;
        //             q.push(neighbor);
        //         }
        //     }
        // }
        // return false;
    }
};
