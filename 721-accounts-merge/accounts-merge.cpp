class Solution {
public:
    void dfs(string email, unordered_map<string, vector<string>>& graph,
             unordered_map<string, bool>& visited, vector<string>& emails) {
        visited[email] = true;
        emails.push_back(email);

        for (auto& nei : graph[email]) {
            if (!visited[nei]) {
                dfs(nei, graph, visited, emails);
            }
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<string>> graph;
        unordered_map<string, string> emailToName;

        // Build graph
        for (auto& acc : accounts) {
            string name = acc[0];
            for (int i = 1; i < acc.size(); i++) {
                emailToName[acc[i]] = name;
                if (i > 1) {
                    graph[acc[1]].push_back(acc[i]);
                    graph[acc[i]].push_back(acc[1]);
                }
            }
        }

        unordered_map<string, bool> visited;
        vector<vector<string>> result;

        // DFS for each component
        for (auto& [email, name] : emailToName) {
            if (!visited[email]) {
                vector<string> emails;
                dfs(email, graph, visited, emails);
                sort(emails.begin(), emails.end());
                emails.insert(emails.begin(), name);
                result.push_back(emails);
            }
        }
        return result;
    }
};
