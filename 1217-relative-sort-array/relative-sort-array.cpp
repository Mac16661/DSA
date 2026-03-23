class Solution {
public:
    // TODO: Counting sort can also be used here
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> mp;
        for(auto i:arr1) mp[i]++;

        vector<int> ans;
        for(int a: arr2) {
            for(int i=0; i<mp[a]; i++) {
                ans.push_back(a);
            }
            mp.erase(a);
        }

        for(auto [key, val]: mp) {
            for(int i=0; i<val; i++) ans.push_back(key);
            mp.erase(key);
        }

        return ans;
    }
};