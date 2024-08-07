#include<bits/stdc++.h>
using namespace std;

// CRAP 
// int maxNewPage(vector<int> & arr, int n, int gap, int i) {
//     int max = 0;
//     int count = 0;
//     while(count<=gap && i<n){
//         max+=arr[i];
//         i++;
//         count++;
//     }
//     if (count < gap+1) return INT_MAX;
//     return max;
// }

// // TODO: Brute soln
// int allocPages(vector<int> arr, int n, int m){
//     // Edge cases
//     if(m > n) return -1;
//     if(m==n) return -1; // Maximum element;

//     int gap = n-m;
//     int maxPages = INT_MAX;

//     for(int i=0; i<n; i++){
//         cout<<maxNewPage(arr,n,gap,i)<<endl;
//         maxPages = min(maxPages, maxNewPage(arr,n,gap,i));
//     }
//     return maxPages;
// }

// int sumOfArr(vector<int> arr, int n){
//     int sum=0;
//     for(int i:arr){
//         sum+=i;
//     }

//     return sum;
// }

// int allocPages(vector<int> arr, int pages){
//     int stu=1, sum=0;

//     for(int i=0; i<arr.size(); i++) {
//         if(sum+arr[i] > pages){
//             sum = arr[i];
//             stu++;
//         }else{
//             sum+=arr[i];
//         }
//     }

//     return stu;
// }

// int pageFind(vector<int> arr, int n, int m){
//     int low = *max_element(arr.begin(), arr.end());
//     int high = sumOfArr(arr,n);

//     if(m > n) return -1;
//     if (m==n) return low;
//     int cntStd;

//     for(int i=low; i<=high; i++){
//         cntStd = allocPages(arr, i);

//         if(cntStd == m) {
//             // cout<<cntStd;
//             return i;}
//     }
    
//     return low;
// }

int countStudents(vector<int> &arr, int pages) {
    int n = arr.size(); //size of array.
    int students = 1;
    long long pagesStudent = 0;
    for (int i = 0; i < n; i++) {
        if (pagesStudent + arr[i] <= pages) {
            //add pages to current student
            pagesStudent += arr[i];
        }
        else {
            //add pages to next student
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}

int findPages(vector<int>& arr, int n, int m) {
    //book allocation impossible:
    if (m > n) return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while (low <= high) {
        int mid = (low + high) / 2;
        int students = countStudents(arr, mid);
        if (students > m) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    vector<int> arr = {25, 46, 28, 49, 24};
    int n = 5;
    int m = 4;
    int ans = findPages(arr, n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}