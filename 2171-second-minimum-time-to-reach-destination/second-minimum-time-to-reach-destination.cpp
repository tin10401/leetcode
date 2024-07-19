class Solution {
public:
    int compute(int step, int time, int change)
    {
        int res = 0;
        while(--step)
        {
            res += time;
            if((res / change) & 1)
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
            graph[edge[0]].push_back({edge[1]});
            graph[edge[1]].push_back({edge[0]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, 1});
        vector<int> count(n + 1);
        vector<int> dis1(n + 1, INT_MAX), dis2(n + 1, INT_MAX);
        dis1[0] = 0;
        while(!q.empty())
        {
            auto [step, node] = q.top(); q.pop();
            count[node]++;
            if(node == n && count[node] == 2) return compute(step, time, change);
            for(auto& nei : graph[node])
            {
                if(count[nei] == 2) continue;
                if(step + 1 < dis1[nei])
                {
                    dis1[nei] = step + 1;
                    q.push({step + 1, nei});
                }
                else if(dis1[nei] != step + 1 && dis2[nei] > step + 1)
                {
                    dis2[nei] = step + 1;
                    q.push({step + 1, nei});
                }
            }
        }
        return 0;
    }
};