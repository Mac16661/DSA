class Solution {
public:
    string decToBinary(int n) {
        string bin = "";
        while (n > 0) {
            // checking the mod 
            int bit = n%2;
            bin.push_back('0' + bit);
            n /= 2;
        }
        
        // reverse the string 
        reverse(bin.begin(), bin.end());
        return bin;
    }

    int hammingWeight(int n) {
        // OPTIMAL 
        int ans = 0;
        // decimal to binary
        while(n) {
           ans++;
           n = (n & (n-1));
        }

        return ans;
    }
};