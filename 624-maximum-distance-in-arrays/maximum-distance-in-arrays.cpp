class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        priority_queue<array<int, 2>> maxHeap;
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> minHeap;
        for(int i = 0; i < arrays.size(); i++)
        {
            minHeap.push({arrays[i].back(), i});
            maxHeap.push({arrays[i].front(), i});
            if(minHeap.size() > 2) minHeap.pop(), maxHeap.pop();
        }
        vector<array<int, 2>> mini, maxi;
        while(!minHeap.empty()) mini.push_back(minHeap.top()), minHeap.pop();
        while(!maxHeap.empty()) maxi.push_back(maxHeap.top()), maxHeap.pop();
        if(maxi.back()[1] != mini.back()[1])
        {
            return abs(maxi.back()[0] - mini.back()[0]);
        }
        return max(abs(maxi[0][0] - mini[1][0]), abs(maxi[1][0] - mini[0][0]));
    }
};