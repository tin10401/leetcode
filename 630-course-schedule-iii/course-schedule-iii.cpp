class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        using ll = long long;
        auto compare = [](const vector<int>& a, const vector<int>& b)
        {
            return a[1] < b[1];
        };
        sort(begin(courses), end(courses), compare);
        priority_queue<int> maxHeap;
        ll time = 0, res = 0;
        for(auto& course : courses)
        {
            time += course[0];
            maxHeap.push(course[0]);
            while(time > course[1]) 
            {
                time -= maxHeap.top();
                maxHeap.pop();
            }
        }
        return maxHeap.size();
    }
};