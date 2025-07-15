class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mpp;
        for(char c:s){
            mpp[c]++;
        }

        priority_queue<pair<int, char>> maxHeap;
        for(auto &[c, f]: mpp){
            maxHeap.push({f,c});
        }

        string ans="";

        while(!maxHeap.empty()) {
            auto [f,c] = maxHeap.top();
            maxHeap.pop();
            ans+= string(f, c);
        }

        return ans;

    }
};