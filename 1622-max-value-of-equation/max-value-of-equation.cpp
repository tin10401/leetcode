class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<array<int, 3>> maxHeap;
        int res = INT_MIN;
        for(auto& p : points)
        {
            int x = p[0], y = p[1];
            while(!maxHeap.empty() && x - maxHeap.top()[1] > k) maxHeap.pop();
            if(!maxHeap.empty())
            {
                res = max(res, x + y + maxHeap.top()[0]);
            }
            maxHeap.push({y - x, x, y});
        }
        return res;
    }
};