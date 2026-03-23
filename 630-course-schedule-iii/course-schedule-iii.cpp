class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        // need to sort by end time in non decreasing order
        sort(courses.begin(), courses.end(), [](const auto &a, const auto &b) {
            return a[1] < b[1];
        });

        priority_queue<int> maxHeap;
        int timeSpent = 0;

        // we are generally trying to complete course with short deadlines and greedily accomodate courses with less duration by eleminating the highest duration course 

        for (const auto &course : courses) {
            int duration = course[0];
            int lastDay = course[1];

            timeSpent += duration;
            maxHeap.push(duration);

            // If time exceeds the deadline, remove the course with the largest duration
            if (timeSpent > lastDay) {
                timeSpent -= maxHeap.top();
                maxHeap.pop();
            }
        }

        return maxHeap.size();

    }
};