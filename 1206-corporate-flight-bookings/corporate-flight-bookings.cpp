class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> reserved(n, 0);

        for(int i=0; i<bookings.size(); i++) {
            int st = bookings[i][0];
            int end = bookings[i][1];
            int seats = bookings[i][2];
            for(int i=st; i<=end; i++){
                reserved[i-1] += seats;
            }
        }

        return reserved;
    }
};