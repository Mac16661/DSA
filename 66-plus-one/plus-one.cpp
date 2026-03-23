class Solution {
public:
    vector<int> plusOne(vector<int>& digit) {
        int n = digit.size();

        if(digit[n-1] == 9) {
            int i = n-1;
            while(i>=0 && digit[i] == 9){
                digit[i]=0;
                i--;
            }
            if(i<0) {
                digit.insert(digit.begin(), 1);
                return digit;
            }
            digit[i] = digit[i] + 1;
        }else{
            digit[n-1] = digit[n-1] + 1;
        }

        return digit;
    }
};