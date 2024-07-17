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
            if(time + course[0] <= course[1])
            {
                time += course[0];
                maxHeap.push(course[0]);
            }
            else if(!maxHeap.empty() && maxHeap.top() > course[0])
            {
                time = time + course[0] - maxHeap.top();
                maxHeap.pop();
                maxHeap.push(course[0]);
            }
            res = max(res, (ll)maxHeap.size());
        }
        return res;
    }
};