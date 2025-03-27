
class Solution {
public:
    int MOD = 1e9+7;
    vector<int> PLE(vector<int> arr) {
        vector<int> left(arr.size());
        stack<pair<int,int>> st;

        for(int i=0; i<arr.size(); i++) {
            int cnt = 1;
            while(!st.empty() && st.top().first > arr[i]){
                cnt+= st.top().second;
                st.pop();
            }
            st.push({arr[i], cnt});
            left[i] = cnt;
        }

        return left;
    }

    vector<int> NLEE(vector<int> arr) {
        vector<int> right(arr.size());
        stack<pair<int, int>> st;

        for(int i=arr.size()-1; i>=0; i--){
            int cnt = 1;
            while(!st.empty() && st.top().first >= arr[i]){
                cnt += st.top().second;
                st.pop();
            }

            st.push({arr[i], cnt});
            right[i] = cnt;
        }
        return right;
    }

    int sumSubarrayMins(vector<int>& arr) {
        
        vector<int> Left = PLE(arr);
        vector<int> Right = NLEE(arr);
        long long sum = 0;
        for(int i=0; i<arr.size(); i++) {
            sum = (sum + (Left[i] * Right[i] % MOD * (long long)arr[i]) % MOD);
        }

        return sum  % MOD;
    }
};