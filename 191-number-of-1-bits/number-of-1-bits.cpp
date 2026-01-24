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
        // decimal to binary
        string s = decToBinary(n);

        // loop through it and find cnt no of set bit and return
        int cnt = 0;
        for(auto i:s){
            if(i=='1') cnt++;
        }

        return cnt;
    }
};