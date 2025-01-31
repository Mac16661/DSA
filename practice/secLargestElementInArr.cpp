#include <bits/stdc++.h>
using namespace std;

int secLargestElement(vector<int> &arr)
{
    int first = 0, second = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if(arr[i] > first) {
            second = first;
            first = arr[i];
        } 
        else if(arr[i] != first && arr[i] > second) {
                second = arr[i];
            }
    }
    return second;
}

int main()
{
    vector<int> arr = {3, 4, 5, 7, 6, 3, 1};
    cout << secLargestElement(arr) << endl;
    return 0;
}