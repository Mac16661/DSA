class Solution {
public:
    pair<int,int> dfs(int node, vector<vector<int>>& graph, vector<int>& visited) {
        visited[node] = 1;
        int cnt = 1;
        int ecnt = 0;
        for(auto adjNode: graph[node]) {
            ecnt++;
            if(visited[adjNode] == 0) {
                pair<int,int> ans = dfs(adjNode, graph, visited);
                ecnt += ans.second;
                cnt += ans.first;
            }
        }
        return make_pair(cnt, ecnt);
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);

        for(auto edge:edges) {
                graph[edge[0]].push_back(edge[1]);
                graph[edge[1]].push_back(edge[0]);
        }

        vector<int> visited(n, 0);
        int completeComponents = 0;

        for(int i=0; i<n; i++) {
            if(visited[i] == 0) {
                auto [nodes, edges] = dfs(i, graph, visited);
                if((edges/2) == (nodes * (nodes - 1)) / 2) {
                    completeComponents++;
                }
            }
        }   

        return completeComponents;
    }
};