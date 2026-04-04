class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> freqMap;
        for(char task: tasks) freqMap[task]++;

        priority_queue<pair<int,char>> maxHeap;
        for(auto& [task, freq] : freqMap) {
            maxHeap.push({freq, task});
        }

        // ready_time, {frq, task}
        queue<pair<int, pair<int, char>>> cooldown;
        int time = 0;

        while(!maxHeap.empty() || !cooldown.empty()) {
            time++;

            if(!cooldown.empty() && cooldown.front().first == time) {
                maxHeap.push(cooldown.front().second);
                cooldown.pop();
            }

            if(!maxHeap.empty()) {
                auto [freq, task] = maxHeap.top();
                maxHeap.pop();
                if(freq > 1) {
                    cooldown.push({time+n+1, {freq - 1, task}});
                }
            }
        }
        return time;
    }
};