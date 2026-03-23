class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& arr) {
       int distance = startFuel;
       int used = 0, i = 0;
        int n = arr.size();

        priority_queue<int> maxFuel;
        while( i < n) {

            if(distance >= target) return used;

            while( i < n && distance >= arr[i][0]) {
                maxFuel.push(arr[i][1]);
                i++;
            }

            if(!maxFuel.empty()) {
                distance += maxFuel.top();
                maxFuel.pop();
                used++;
            }else{
                return -1;
            }

        }

        while(!maxFuel.empty() && distance < target) {
            distance += maxFuel.top();
            maxFuel.pop();
            used++;
        }

        return (distance >= target) ? used : -1;

    }
};