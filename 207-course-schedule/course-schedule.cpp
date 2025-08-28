class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& visited) {
        visited[node] = 1; 

        for (auto neg : graph[node]) {
            if (visited[neg] == 1) return true; 
            if (visited[neg] == 0 && dfs(neg, graph, visited)) return true;
        }

        visited[node] = 2; 
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& preq) {
        vector<vector<int>> graph(numCourses);
        for(auto p:preq) {
            graph[p[1]].push_back(p[0]);
        }

        vector<int> visited(numCourses, 0);

        for(int i=0; i<numCourses; i++) {
            if(visited[i] == 0 && dfs(i, graph, visited)) return false;
        }

        return true;
    }
};