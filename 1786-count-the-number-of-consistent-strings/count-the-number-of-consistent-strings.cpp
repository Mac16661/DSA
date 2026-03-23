class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<int> mt;
        int ans = 0;
        for(char c:allowed) mt.insert(c);

        for(auto word:words) {
            int cnt=1;
            for(char c: word) {
                if(mt.find(c) == mt.end()){
                    cnt=0;
                    break;
                }
            }
            ans += cnt;
        }

        return ans;
    }
};