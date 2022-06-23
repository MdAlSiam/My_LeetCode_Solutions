class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(),
            [] (const auto  &a, const auto &b) {
                return a[1] < b[1];
            }
        );

        priority_queue<int> pq;

        int curr_time = 0;

        for (vector<int> course : courses) {
            pq.push(course[0]);
            curr_time += course[0];

            if (curr_time > course[1]) {
                curr_time -= pq.top();
                pq.pop();
            }
        }

        return pq.size();
    }
};