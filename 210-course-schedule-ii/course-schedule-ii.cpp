class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // building graph
        int n = numCourses;
        vector<vector<int>> graph(n);

        vector<int> indegree(n, 0);
        for(auto &edge: prerequisites) {
            int u = edge[0];
            int v = edge[1];

            graph[v].push_back(u);
            indegree[u]++;
        }

        //KHAN'S Algorithm
        

        // for(int u = 0; u < n; u++) {
        //     for(int v:graph[u]) {
        //         indegree[v]++;
        //     }
        // }

        queue<int> q;
        // Node with indegree 0 should be pushed into the queue
        for(int i =0; i<n; i++) {
            if(indegree[i]==0) q.push(i);
        }

        vector<int> topo;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            // exploring edges of current node
            for(auto neigh: graph[node]) {
                indegree[neigh]--;
                if(indegree[neigh] == 0) q.push(neigh);
            }
        }

        if(topo.size() == n) return topo;

        return {};
    }
};