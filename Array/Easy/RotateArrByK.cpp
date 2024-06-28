#include<bits/stdc++.h>
using namespace std;

// Brute force approach
void RotateRight(int arr[], int n, int k) {

    if(n==0) return;

    k = k % n;

    if(k > n) return; //dont know in wchih case this will execute

    int temp[k];

    for( int i=n-k; i<n; i++) {
        temp[i - n+k] = arr[i];
    }

    for( int i = n-k-1; i >= 0; i--) {
        arr[i+k] = arr[i];
    }

    for( int i = 0; i<k; i++) {
        arr[i] = temp[i];
    }
}

void Rotatetoleft(int arr[], int n, int k)
{
  if (n == 0)
    return;
  k = k % n;
  if (k > n)
    return;
  int temp[k];
  for (int i = 0; i < k; i++)
  {
    temp[i] = arr[i];
  }
  for (int i = 0; i < n - k; i++)
  {
    arr[i] = arr[i + k];
  }
  for (int i = n - k; i < n; i++)
  {
    arr[i] = temp[i - n + k];
  }
}

// TODO: This version of rotate left is optimized

void Reverse(int arr[], int start, int end)
{
  while (start <= end)
  {
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }
}
// Function to Rotate k elements to left
void Rotateeletoleft(int arr[], int n, int k)
{
  // Reverse first k elements
  Reverse(arr, 0, k - 1);
  // Reverse last n-k elements
  Reverse(arr, k, n - 1);
  // Reverse whole array
  Reverse(arr, 0, n - 1);
}

int main() {

    int n = 7;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int k = 2;
    Brute(arr, k ,n);
    return 0;
}