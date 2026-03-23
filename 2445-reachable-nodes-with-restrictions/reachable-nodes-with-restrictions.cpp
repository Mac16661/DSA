class Solution {
public:
    int dfs(int node, vector<vector<int>>& graph, vector<int>& visited) {
        visited[node] = 1;
        int cnt = 1;

        for(auto adjNode: graph[node]) {
            if(visited[adjNode] == 0) {
                cnt += dfs(adjNode, graph, visited);
            }
        }
        // cout<<node<<" "<<cnt<<endl;
        return cnt;
    }

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> graph(n);

        // inserting restricted for constant time access;
        // unordered_set<int> st(restricted.begin(), restricted.end());

        for(auto edge:edges) {
            // if(!st.count(edge[0]) && !st.count(edge[1])){
                graph[edge[0]].push_back(edge[1]);
                graph[edge[1]].push_back(edge[0]);
            // }
        }

        vector<int> visited(n, 0);
        for(auto i:restricted) {
            visited[i] = -1;
        }

        return dfs(0, graph, visited);
    }
};