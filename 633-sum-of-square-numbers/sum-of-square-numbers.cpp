class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c==1) return true;

        int i = 0;
        int j = sqrt(c);

        while(i<=j) {
            long a = i*i;
            long b = j*j;

            if((a+b) == c) return true;
            else if((a+b) < c) i++;
            else j--;
        }

        return false;
    }
};