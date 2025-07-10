class Solution {
public:
    // calculating time taken to cover dist with given speed
    double distReached(vector<int> dist, int speed) {
        int r=0;
        double time = 0.0;
        while(r < dist.size()) {
            double t = (double)dist[r]/speed;
            if(r == dist.size()-1) {
                time += t;
                break;
            }
            time += ceil(t);
            r++;
        }

        return time;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        // Brute
        // int maxSpeed = 0;
        // for(auto i:dist) maxSpeed = max(maxSpeed, i);

        // for(int i=1; i<=maxSpeed; i++){
        //     cout<<i<< " -> "<<distReached(dist, i)<<endl;
        //     if(distReached(dist, i) <= hour) return i;
        // }

        // return -1;

        // Optimal
        int l=0;
        int r = 1e7;
        int ans = -1;

        while(l<=r){
            int mid = (l+r)/2;

            if(distReached(dist, mid) <= hour) {
                r = mid-1;
                ans = mid;
            }else{
                l = mid+1;
            }
        }

        return ans;
    }
};