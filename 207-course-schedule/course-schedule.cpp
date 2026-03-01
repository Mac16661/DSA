class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>&visited ) {
        visited[node] = 2; // under processing

        for (auto neigh: graph[node]) {
            if(visited[neigh] == 2)
                return false;
            
            if(visited[neigh] == 0 && !dfs(neigh, graph, visited))
                return false;
        }

        visited[node] = 1;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
         // Dfs cycle detection
        int n =  numCourses;
        vector<vector<int>> graph(n);

        for(auto edge: prerequisites) {
            graph[edge[0]].push_back(edge[1]);
            // graph[edge[1]].push_back(edge[0]);
        }

        vector<int> visited(n, 0);

        for(int i=0; i<n; i++) {
            if(visited[i] == 0) {
                if(!dfs(i, graph, visited))
                    return false;
            }
        }

        return true;
    }
};