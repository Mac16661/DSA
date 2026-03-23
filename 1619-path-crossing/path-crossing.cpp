class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<string, int> mp;
        
        int x = 0, y = 0;
        mp["0,0"] = 1;

        for (char c : path) {
            if (c == 'N') y++;
            else if (c == 'S') y--;
            else if (c == 'E') x++;
            else if (c == 'W') x--;

            string key = to_string(x) + "," + to_string(y);
            // cout<<key<<endl;
            mp[key]++;               
            if (mp[key] > 1) return true;
        }

        return false;
    }
};
