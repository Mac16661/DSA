class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        const int MOD = 1e9 + 7;
        long long ans = 0;

        unordered_map<int, long long> count;
        for(int x:arr) count[x]++;

        vector<int> keys;
        for(auto &p: count) keys.push_back(p.first);
        sort(keys.begin(), keys.end());

        for(int i=0; i<(int)keys.size(); i++) {
            for(int j=i; j<(int)keys.size(); j++) {
                long long a = keys[i];
                long long b = keys[j];
                long long c = target - a - b;

                if(c<b) continue; // ensuer a <=b <= c
                if(!count.count(c)) continue;

                // cases 
                if(a < b && b < c) {
                    ans+= count[a] * count[b] * count[c];
                }else if(a == b && b < c) {
                    ans += (count[a] * (count[a] - 1) / 2) * count[c];
                }else if(a < b && b == c) {
                    ans += count[a] * (count[b] * (count[b] - 1) / 2);
                }else if(a == b && b == c) {
                    ans += (count[a] * (count[a] - 1) * (count[a] - 2)) / 6;
                }

                ans %= MOD;
            }
        }

        return (int) ans;    
    }
};