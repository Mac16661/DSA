#include<bits/stdc++.h>
using namespace std;

void PntNTimes(int n = 5){
    if(n < 1) return;
    // PntNTimes(n-1); // To print in ascending order 
    cout<<"Mac -> "<<n<<endl;
    PntNTimes(n-1); // to print n in reverse order
}

int SumOfN(int n = 5, int result = 0) {
    if(n < 1) return 0;

    result+= (n + SumOfN(n-1));

    return result;

}

// With return 
void sumOFN(int i, int sum){
   
   // Base Condition.
   if(i<1)
   {
       cout<<sum<<endl;
       return;
   }

   // Function call to increment sum by i till i decrements to 1.
   sumOFN(i-1,sum+i);

}

int NFact(int n) {
    if(n <= 0) return 1;

    int fact = n * NFact(n-1);
    return fact;
}

void RevArr(vector<int> &arr, int i, int j){
    if(i>j) return;

    swap(arr[i], arr[j]);

    RevArr(arr, i+1, j-1);
}

bool StrPalind(string s, int i, int j) {
    if(i>j) return true;

    if(s[i] == s[j]) return true && StrPalind(s, i+1, j-1);
    else return false;
}

int Fib(int n){
    if(n==1) return n;
    if(n<=0) return 0;

    int last = Fib(n-1);
    int slast = Fib(n-2);
    
    return last+slast;
}

void FibIter(int n) {
    int n1 = 0;
    int n2 = 1;
    cout<<n1<<" "<<n2<<" ";
    for(int i=2; i<n; i++) {
        int n3 = n1+ n2;
        cout<<n3<<" ";
        n1 = n2;
        n2 = n3;
    }
    cout<<endl;
}

int main() {
    // PntNTimes();
    // cout<<SumOfN(5, 0)<<endl;
    // sumOFN(5,0);
    // cout<<"NFact - > "<<NFact(3)<<endl;
    // vector<int> arr = {5,4,3,2,1};
    // RevArr(arr, 0 , arr.size()-1);

    // for(auto it: arr) {
    //     cout<<it<<" ";
    // }
    // cout<<endl;

    // string s = "ABCBA";

    // cout<<StrPalind(s, 0, s.length()-1)<<endl;

    // cout<<Fib(6)<<endl;

    FibIter(10);

    return 0;
}