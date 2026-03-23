class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long timeTaken = 0;
        long long waitTime = 0;

        for(auto customer: customers){
            int arrivalTime = customer[0];
            int processingTime = customer[1];
        
            timeTaken = max(timeTaken, (long long)arrivalTime);
            timeTaken += processingTime;
            waitTime += timeTaken - arrivalTime;
        }

        return (double)waitTime / customers.size();
    }
};