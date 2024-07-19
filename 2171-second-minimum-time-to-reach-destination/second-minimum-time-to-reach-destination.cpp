class Solution {
public:
    int compute(int step, int time, int change)
    {
        int res = 0;
        while(--step)
        {
            res += time;
            if((res / change) % 2)
            {
                res = (res / change + 1) * change;
            }
        }
        return res + time;
    }
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> graph(n + 1);
        for(auto& edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, 1});
        vector<int> count(n + 1, 10001);
        while(!minHeap.empty() && minHeap.top().first <= count[n] + 1)
        {
            auto [cost, node] = minHeap.top();
            minHeap.pop();
            while(!minHeap.empty() && minHeap.top().first == cost && minHeap.top().second == node) minHeap.pop();
            count[node] = min(count[node], cost);
            if(node == n && cost > count[node])
            {
                return compute(cost, time, change);
            }
            if(cost > count[node] + 1) continue;
            for(auto& nei : graph[node])
            {
                minHeap.push({cost + 1, nei});
            }
        }
        return compute(count[n] + 2, time, change);
    }
};