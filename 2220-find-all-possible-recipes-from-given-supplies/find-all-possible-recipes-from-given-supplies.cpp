class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> graph; 
        unordered_map<string, int> indegree; 

        for (auto& r : recipes) indegree[r] = 0;

        for (int i = 0; i < recipes.size(); ++i) {
            for (auto& ing : ingredients[i]) {
                // only count towards indegree if ing is not a direct supply
                if (!indegree.count(ing)) {
                    // nothing; we'll handle via queue
                }
                graph[ing].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }
        

        queue<string> q;
        unordered_set<string> available(supplies.begin(), supplies.end());
        for (auto& s : supplies) q.push(s);

        vector<string> result;

        while (!q.empty()) {
            string item = q.front(); q.pop();

            // Check which recipes depend on this item
            if (graph.count(item)) {
                for (auto& recipe : graph[item]) {
                    if (--indegree[recipe] == 0) {
                        result.push_back(recipe);
                        q.push(recipe); 
                    }
                }
            }
        }
        return result;
    }
};