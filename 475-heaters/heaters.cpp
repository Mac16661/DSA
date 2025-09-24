class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int maxRadius = 0;
        int curr = 0;

        for (int i = 0; i < houses.size(); i++) {
            // move to the heater that is closer to houses[i]
            while (curr < heaters.size() - 1 &&
                   abs(heaters[curr + 1] - houses[i]) <= abs(heaters[curr] - houses[i])) {
                curr++;
            }
            maxRadius = max(maxRadius, abs(heaters[curr] - houses[i]));
        }

        return maxRadius;

    }
};