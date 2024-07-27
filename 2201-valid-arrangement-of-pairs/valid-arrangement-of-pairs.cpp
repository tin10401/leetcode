class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<vector<int>> res;
    void dfs(int node)
    {
        while(!graph[node].empty())
        {
            int nei = graph[node].back();
            graph[node].pop_back();
            dfs(nei);
            res.push_back({node, nei});
        }
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int last = -1;
        unordered_map<int, int> out, in;
        for(int i = 0; i < pairs.size(); i++)
        {
            int a = pairs[i][0], b = pairs[i][1];
            out[a]++;
            in[b]++;
            graph[a].push_back(b);
            last = a;
        }
        for(auto& p : graph)
        {
            int i = p.first;
            if(out[i] - in[i] == 1) last = i;
        }
        if(last == -1) last = graph.begin()->first;
        dfs(last);
        reverse(res.begin(), res.end());
        return res;

    }
};