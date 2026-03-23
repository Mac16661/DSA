class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int left=0, right = 1;
        int res = 1;
        string prev = "";

        while(right < arr.size()) {
            if(arr[right-1] > arr[right] && prev != ">") {
                res = max(res, right-left+1);
                right++;
                prev = ">";
            }else if(arr[right-1] < arr[right] && prev != "<") {
                res = max(res, right-left+1);
                right++;
                prev = "<";
            }else {
                if(arr[right-1] == arr[right]) {
                    right++;
                }

                left = right-1;
                prev = "";
            }
        }

        return res;
    }
};