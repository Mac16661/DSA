class Car{
public:
    Car(int pos, int speed){
        this->pos = pos;
        this->speed= speed;
    }
    int pos;
    int speed;
};

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car> cars;

        for(int i=0; i<position.size(); i++) {
            cars.emplace_back(position.at(i), speed.at(i));
        }

        // writing custom comparator function
        sort(cars.begin(), cars.end(), [] (const Car& a, const Car& b) {
            return a.pos < b.pos;
        });

        stack<float> st;

        for(int i=0; i < position.size(); i++) {
            float time = (target-cars.at(i).pos)/(float)cars.at(i).speed;


            while(!st.empty() && st.top() <= time) st.pop();

            st.push(time);
        }

        return st.size();

    }
};