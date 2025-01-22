class Solution {
public:
    string largestOddNumber(string num) {
        int left = 0;
        int right = num.length()-1;
        

        while(left <= right) {
            int digit = num[right] - '0'; // convertig char to int in cpp
            if(digit % 2 != 0) { // If odd number
                // Return substring
                return num.substr(0,right+1);
            }else{
                right--;
            }
        }

        return "";
    }
};