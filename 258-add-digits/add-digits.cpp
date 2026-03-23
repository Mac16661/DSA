class Solution {
public:
    int sumOfDigit(int num) {
        int sum = 0;
        while(num) {
            sum += num%10;
            num /= 10;
        }

        return sum;
    }

    int addDigits(int num) {
        while((num / 10) != 0) {
            num = sumOfDigit(num);
        }
        return num;
    }
};