class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto& edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int res = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            vector<int> dis(n, INT_MAX);
            dis[i] = 0;
            queue<int> q;
            q.push(i);
            vector<int> parent(n, -1);
            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                bool found = false;
                for(auto& nei : graph[node])
                {
                    if(dis[node] + 1 < dis[nei]) 
                    {
                        dis[nei] = dis[node] + 1;
                        parent[nei] = node;
                        q.push(nei);
                    }
                    else 
                    {
                        if(parent[nei] != node && parent[node] != nei)
                        {
                            res = min(res, dis[nei] + dis[node] + 1);
                            found = true;
                            break;
                        }
                    }
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};