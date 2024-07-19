class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size();
        vector<vector<array<int, 2>>> list(n);
        vector<vector<int>> graph(n);
        for(auto& e : edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        for(int i = 0; i < n; i++)
        {
            priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> minHeap;
            for(auto& nei : graph[i])
            {
                minHeap.push({scores[nei], nei});
                if(minHeap.size() > 3) minHeap.pop();
            }
            while(!minHeap.empty()) 
            {
                list[i].push_back(minHeap.top()); minHeap.pop();
            }
        }

        int res = -1;
        for(int i = 0; i < n; i++)
        {
            for(auto& nei : graph[i])
            {
                for(auto& [c1, n1] : list[i])
                {
                    for(auto& [c2, n2] : list[nei])
                    {
                        if(n1 != nei && n2 != i && n1 != n2)
                        {
                            res = max(res, scores[i] + scores[nei] + c1 + c2);
                        }
                    }
                }
            }
        }
        return res;
    }
};