class Solution {
public:
    bool checkPerfectNumber(int num) {
        // if( num==6 or num==28 or num==496 or num==8128 or num==33550336) return true;
        int sum=0;
        for(int i=1; i<num; i++) {
            if(num%i == 0) {
                sum+=i;
                // cout<<i<<" ";
            }
        }
        // cout<<endl<<sum;
        return sum==num;
    }
};