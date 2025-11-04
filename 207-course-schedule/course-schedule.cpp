class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // building grpah
        int n = numCourses;
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);

        for(auto &edge: prerequisites) {
            int u = edge[0];
            int v = edge[1];

            graph[v].push_back(u);
            indegree[u]++; // indegree 
        }

        // topo sort
        vector<int> topo;
        queue<int> q;
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(int neigh: graph[node]) {
                indegree[neigh]--;
                if(indegree[neigh] == 0) q.push(neigh);
            }
        }

        if(n==topo.size()) return true;
        return false;
    }
};