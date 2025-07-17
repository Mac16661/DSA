class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int> mpp;
        for(int i:barcodes) mpp[i]++;

        priority_queue<pair<int,int>> maxHeap;
        for(auto [num,freq]: mpp) maxHeap.push({freq,num});

        vector<int> res;
        while(!maxHeap.empty()){
            vector<pair<int, int>> t(2, make_pair(0,0));

            for(int i=0; i<t.size() && !maxHeap.empty(); i++) {
                t[i] = {maxHeap.top().first-1, maxHeap.top().second};
                res.push_back(maxHeap.top().second);
                maxHeap.pop();
            }

            for(int i=0; i<t.size(); i++){
                if(t[i].first > 0) maxHeap.push(t[i]);
            }
        }

        return res;
    }
};