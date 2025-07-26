class Solution {
public:
    // DP solution 
    // int findTheWinner(int n, int k) {
    //     int winner = 0;
        
    //     // need atleast 2 number, i is representing the total no
    //     for(int i=2; i<=n;i++) {
    //         winner = (winner + k) % i;
    //     }

    //     // when i = 2 -> if there are 2 player left who would win
    //     // fi  i = 3 -> if there are 3 players, who would win (doing the whole thing in bottoms up approach)

    //     return winner+1;
    // }

    // Recursion with subproblem solution 
    int rec(int n, int k){
        if(n==1) return 0;

        return (rec(n-1, k) + k) % n;
    }

    int findTheWinner(int n, int k) {
        return rec(n, k) + 1;
    }
};