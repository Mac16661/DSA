class Solution {
public:
    int sumByD(vector<int> &arr, int div) {
    int n = arr.size(); //size of array
    //Find the summation of division values:
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ceil((double)(arr[i]) / (double)(div));
    }
    return sum;
}
    
    int smallestDivisor(vector<int>& arr, int limit) {
        // int low = 0;
        // int high = high = *max_element(nums.begin(), nums.end());

        // if (nums.size() > threshold) return -1;

        // while(low<=high){
        //     int mid =(low+high)/2;

        //     int s = sumT(nums, mid);

        //     if(s <= threshold){
        //         high = mid -1;
        //     }else{
        //         low = mid +1;
        //     }
        // }

        // return low;

        int n = arr.size();
    if (n > limit) return -1;
    int low = 1, high = *max_element(arr.begin(), arr.end());

    //Apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        if (sumByD(arr, mid) <= limit) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
    }
};