class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& state) {
        state[node] = 1; // visiting

        for (int neigh : graph[node]) {
            if (state[neigh] == 1) 
                return true; // cycle detected
            if (state[neigh] == 0 && dfs(neigh, graph, state))
                return true;
        }

        state[node] = 2; // done visiting
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto& edge : prerequisites) {
            int a = edge[0];
            int b = edge[1];
            graph[b].push_back(a); // correct direction
        }

        vector<int> state(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0) {
                if (dfs(i, graph, state)) 
                    return false; // cycle found
            }
        }

        return true; // no cycle
    }
};
