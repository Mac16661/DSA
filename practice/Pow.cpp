#include<iostream>
using namespace std;

class Solution{
    public:
        int pow(int x, int n) {
            if(n <= 0) return 1;

            return x * pow(x, n-1);
        }
};

int main() {
    Solution *s = new Solution();
    cout<<s->pow(2,3)<<endl;
    return 0;
}