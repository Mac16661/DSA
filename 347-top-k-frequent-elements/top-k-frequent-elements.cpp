class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for(auto num: nums) {
            mpp[num]++;
        }

        auto cmp = [&mpp](const int& a, const int& b) {
            return mpp[a] > mpp[b];  // creating min heap
        };

        priority_queue<int, vector<int>, decltype(cmp)> minHeap(cmp);

        for (auto& pair : mpp) {
            minHeap.push(pair.first);

            if(minHeap.size() > k) minHeap.pop();
        }

        vector<int> ans;

        while(!minHeap.empty()) {
            ans.push_back(minHeap.top());
            minHeap.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};