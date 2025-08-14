class Solution {
public:
    string convertToTitle(int num) {
        string s="";

        while(num) {
            num--; // to handle z
            int digit = num%26;
            num = num/26;

            s.push_back('A'+digit); // converting it to character 
        }

        reverse(s.begin(), s.end());
        return s;
    }
};