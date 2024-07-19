class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();
        vector<unordered_set<int>> graph(n);
        for(auto& edge : edges)
        {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        vector<int> leaf;
        for(int i = 0; i < n; i++)
        {
            int u = i;
            while(graph[u].size() == 1 && coins[u] == 0)
            {
                int v = *graph[u].begin();
                graph[u].erase(v);
                graph[v].erase(u);
                u = v;
            }
            if(graph[u].size() == 1) leaf.push_back(u);
        }
        for(int i = 0; i < 2; i++)
        {
            vector<int> next;
            for(auto& u : leaf)
            {
                if(graph[u].size() == 1)
                {
                    int v = *graph[u].begin();
                    graph[v].erase(u);
                    graph[u].erase(v);
                    if(graph[v].size() == 1) next.push_back(v);
                }
            }
            leaf = next;
        }
        int res = 0;
        for(int i = 0; i < n; i++) res += graph[i].size();
        return res;
    }
};