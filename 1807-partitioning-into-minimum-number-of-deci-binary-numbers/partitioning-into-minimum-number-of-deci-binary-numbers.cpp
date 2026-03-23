class Solution {
public:
    int minPartitions(string n) {
        int maxi = INT_MIN;
        for(char c:n) {
            int num = c - '0';
            // cout<<num<<endl;
            maxi = max(maxi, num);
        }

        return maxi;
    }
};