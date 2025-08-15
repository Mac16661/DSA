class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = sqrt(area);
        while (area % w != 0) {
            w--; // go down until w divides area
        }
        return {area / w, w};

    }
};