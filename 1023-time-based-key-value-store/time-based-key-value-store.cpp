class TimeMap {
public:
    unordered_map<string, vector<pair<int,string>>> mpp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        auto &arr = mpp[key];
        arr.push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!mpp.count(key)) return "";
        
        auto &arr = mpp[key];
        string ans = "";
        int low = 0;
        int high = arr.size()-1;

        while(low <= high) {
            int mid = (low+high)/2;

            if(arr[mid].first <= timestamp) {
                ans = arr[mid].second;
                // cout<<ans;
                low = mid+1;
            }
            else  high=mid-1;
        }
        // cout<<endl;

        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */