class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> seats(n+1, 0);
        vector<int> ans(n, 0);

        for(int i=0; i<bookings.size(); i++) {
            int start = bookings[i][0];
            int end = bookings[i][1];

            seats[start-1] += bookings[i][2];
            if(end<n){
                seats[end] -= bookings[i][2];
            }
        }

        int curr = 0;
        for(int i=0; i<n; i++) {
            curr = curr + seats[i];
            ans[i] = curr;
        }

        return ans;
    }
};