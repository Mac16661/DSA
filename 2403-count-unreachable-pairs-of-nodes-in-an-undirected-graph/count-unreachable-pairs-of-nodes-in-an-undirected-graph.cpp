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
        return cnt;
    }

    long long fastSum(const vector<int>& components) {
        long long totalSum = 0, totalSq = 0;

        for (int x : components) {
            totalSum += x;
            totalSq += 1LL * x * x;
        }

        return (totalSum * totalSum - totalSq) / 2;
    }


    long long countPairs(int n, vector<vector<int>>& edges) {
        // cnt number of nodes in each connected components and multiply

        vector<vector<int>> graph(n);

        for(auto edge:edges) {
                graph[edge[0]].push_back(edge[1]);
                graph[edge[1]].push_back(edge[0]);
        }

        vector<int> visited(n, 0);
        vector<int> components;

        for(int i=0; i<n; i++) {
            if(visited[i] == 0) {
                components.push_back(dfs(i, graph, visited));
            }
        }   
        
        // n = components.size();
        // long long sum = 0;
        // for(int i=0; i<n; i++) {
        //     for(int j=i+1; j<n; j++) {
        //         sum += 1LL * components[i] * components[j];
        //     }
        // }

        return fastSum(components);
    }
};