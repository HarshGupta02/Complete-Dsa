/*

so here, we first sort the courses on the basis of endTime.
then we check that if we can include the current course then take it and update the end time.
if we cannot take it then, we check the max duration of the course already taken. if it is
greater than the current course duration, then we replace it with the current course duration as
now the end time will decrease for all the courses that are after the max duration course and which
is beneficial as we are finishing the courses more early that their duration, and hence giving 
chance for more courses to complete them before their endTime.

*/

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        sort(courses.begin(), courses.end(), [&](const vector<int> &a, const vector<int> &b){
            if(a[1] != b[1]) return a[1] < b[1];
            return a[0] < b[0];
        });
        priority_queue<int> pq;
        int endTime = 1;
        for(int i = 0; i < n; i ++) {
            if((endTime + courses[i][0] - 1) <= courses[i][1]) {
                pq.push(courses[i][0]);
                endTime += courses[i][0];
            }else {
                if(pq.empty()) continue;
                int max_duration = pq.top();
                if(max_duration >= courses[i][0]) {
                    pq.pop();
                    pq.push(courses[i][0]);
                    endTime -= max_duration;
                    endTime += courses[i][0];
                }
            }
        }
        return (int)pq.size();
    }
};