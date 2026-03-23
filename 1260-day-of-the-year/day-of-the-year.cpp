class Solution {
public:
    int dayOfYear(string date) {
        int year, month, day;
        char dash; 
        stringstream ss(date);
        ss >> year >> dash >> month >> dash >> day;

        vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 
                                   31, 31, 30, 31, 30, 31};

        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            daysInMonth[1] = 29;
        }

        int dayCnt = 0;

        for (int i = 0; i < month - 1; i++) {
            dayCnt += daysInMonth[i];
        }

        dayCnt += day;

        return dayCnt;
    }
};
