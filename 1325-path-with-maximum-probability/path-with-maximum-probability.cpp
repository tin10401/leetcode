class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<double, int>>> graph(n);
        for(int i = 0; i < edges.size(); i++)
        {
            auto & edge = edges[i];
            graph[edge[0]].push_back({succProb[i], edge[1]});
            graph[edge[1]].push_back({succProb[i], edge[0]});
        }
        bitset<10000> vis;
        priority_queue<pair<double, int>> maxHeap;
        maxHeap.push({1, start_node});
        while(!maxHeap.empty())
        {
            auto [prob, node] = maxHeap.top();
            maxHeap.pop();
            if(node == end_node)
            {
                return prob;
            }
            if(vis[node])
            {
                continue;
            }
            vis.set(node);
            for(auto & edge : graph[node])
            {
                if(!vis[edge.second])
                {
                    maxHeap.push({prob * edge.first, edge.second});
                }
            }
        }
        return 0;
    }
};