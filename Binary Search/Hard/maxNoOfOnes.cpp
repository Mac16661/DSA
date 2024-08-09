#include<bits/stdc++.h>
using namespace std;

int firstOcc(vector<int> arr, int n) {
    int low=0; int high=n;
    int ans = n;
    while(low<=high){
        int mid = (low+high)/2;

        if(arr[mid] >= 1){
            ans = mid;
            high = mid - 1;
        }else if(arr[mid] < 1){
            low = mid+1;
        }
    }
    return ans;
}

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    int cnt = 0;
    int index = -1;

    for(int i=0; i<n; i++){
        int cnt_once = m - firstOcc(matrix[i], m);
        if(cnt_once > cnt){
            cnt = cnt_once;
            index = i;
        }
    }
    
    return index;
}

int main() {
    vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    int n = 3, m = 3;
    cout << "The row with maximum no. of 1's is: " <<
         rowWithMax1s(matrix, n, m) << '\n';
    return 0;
}