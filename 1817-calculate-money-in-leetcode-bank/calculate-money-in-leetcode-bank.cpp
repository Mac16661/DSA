class Solution {
public:
    int totalMoney(int n) {
        // n*(n+1) / 2;
        int sum = 0;
        int base = 0;
        for(int i=1; i<=n; i++) {
            if(i%7 == 0) {
                sum += 7+base;
                base++;
            }else {
                int temp = i%7;
                sum += (temp+base);
            }
        }   
        return sum;
    }
};