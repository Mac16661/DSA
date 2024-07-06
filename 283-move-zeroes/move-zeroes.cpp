class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        
        int j = - 1;

       for(int i =0; i<arr.size(); i++) {
        if(arr[i] == 0) {
            j = i;
            break;
        }
       }

       if(j == -1) return;

       for (int i = j + 1; i < arr.size(); i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }
    }

    
};