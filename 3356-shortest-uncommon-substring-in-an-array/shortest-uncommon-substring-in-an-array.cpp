class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n = arr.size();
        unordered_map<string, int> owner;  
        // substring -> index of unique owner, or -1 if shared

        for (int idx = 0; idx < n; idx++) {
            const string& s = arr[idx];
            int len = s.size();

            unordered_set<string> seen; 
            for (int i = 0; i < len; i++) {
                string temp = "";
                for (int j = i; j < len; j++) {
                    temp.push_back(s[j]);
                    if (seen.count(temp)) continue;
                    seen.insert(temp);

                    if (owner.count(temp) == 0) {
                        owner[temp] = idx;
                    } else {
                        if (owner[temp] != idx)
                            owner[temp] = -1;
                    }
                }
            }
        }

        vector<string> ans(n, "");

        for (int idx = 0; idx < n; idx++) {
            const string& s = arr[idx];
            int len = s.size();

            string best = "";
            for (int i = 0; i < len; i++) {
                string temp = "";
                for (int j = i; j < len; j++) {
                    temp.push_back(s[j]);

                    if (owner[temp] == idx) {
                        if (best == "" ||
                            temp.size() < best.size() ||
                            (temp.size() == best.size() && temp < best)) {
                            best = temp;
                        }
                    }
                }
            }

            ans[idx] = best;
        }

        return ans;
    }
};
