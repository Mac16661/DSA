class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        // vector<vector<int>> candidate;
        // for(int i=0; i<nums1.size(); i++){
        //     candidate.push_back({nums1[i], nums2[i]});
        // }

        // sort(candidate.begin(), candidate.end(), [](auto &a, auto &b) {
        //     return a[1] > b[1]; // decreasing order
        // });

        // int sum = 0;
        // int total = 0;

        // // i think i need to keep track of the (min of k window) or total sum of k window
        // priority_queue<int, vector<int>, greater<int>> minHeap;

        // for(auto c:candidate){
        //     // cout<<c[0]<<" "<<c[1]<<endl;
        //     sum += c[0]; // sum
        //     minHeap.push(sum);

        //     if(minHeap.size() > k) {
        //         sum-=minHeap.top();
        //         minHeap.pop();
        //     }

        //     total = max(total, sum * c[1]);
        // }

        // return total;

        vector<pair<int, int>> candidates(nums1.size());

        for(int i=0; i<nums1.size(); i++) candidates[i] = {nums2[i], nums1[i]};

        sort(candidates.rbegin(), candidates.rend()); // so sort in decreasing order

        long speedSum = 0, ans = 0;

        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto &[e, s]: candidates) {
            pq.push(s);
            speedSum += s;

            if(pq.size() > k) {
                speedSum -= pq.top();
                pq.pop();
            }

            if (pq.size() == k) {
                ans = max(ans, (speedSum * e));
            }
            
        }
        return ans;
    }
};