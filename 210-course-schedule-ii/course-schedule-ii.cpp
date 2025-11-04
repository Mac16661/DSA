class Solution {
public:
    void dfsTopoSort(int node, vector<vector<int>> &graph, vector<int> &visited, stack<int> &st, bool &hasCycle) {
        visited[node] = 1; // 1 = visiting

        for (int neigh : graph[node]) {
            if (visited[neigh] == 0)
                dfsTopoSort(neigh, graph, visited, st, hasCycle);
            else if (visited[neigh] == 1) {
                hasCycle = true; // found a back edge
                return;
            }
        }

        visited[node] = 2; // 2 = done
        st.push(node);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> graph(n);

        for (auto &edge : prerequisites) {
            int u = edge[0];
            int v = edge[1];
            graph[v].push_back(u); // v → u
        }

        vector<int> visited(n, 0);
        stack<int> st;
        bool hasCycle = false;

        for (int i = 0; i < n; i++) {
            if (visited[i] == 0)
                dfsTopoSort(i, graph, visited, st, hasCycle);
        }

        if (hasCycle) return {}; // No valid order if cycle exists

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};
