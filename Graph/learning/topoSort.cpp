#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, 
             vector<int>& vis, stack<int>& st) {
        
        vis[node] = 1;

        for (int neigh : graph[node]) {
            if (!vis[neigh]) {
                dfs(neigh, graph, vis, st);
            }
        }

        st.push(node);
    }

    bool dfsCycleDetection(int node, vector<vector<int>>& graph, vector<int>& vis, stack<int>& st) {
        vis[node] = 2; // Put it in the processing mode

        for(auto neigh: graph[node]) {
           // If neighbor is currently being visited → cycle
            if (vis[neigh] == 2)
                return true;

            // If not visited → DFS
            if (vis[neigh] == 0) {
                if (dfsCycleDetection(neigh, graph, vis, st))
                    return true;
            }
        }

        vis[node] = 1;
        st.push(node);
        return false;
    }

    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        // Build adjacency list
        vector<vector<int>> graph(V);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }

        stack<int> st;
        vector<int> vis(V, 0);

        // Run DFS for all components
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, graph, vis, st);
            }
        }

        // Extract result from stack
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};