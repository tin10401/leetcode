class Solution {
public:
    vector<int> res, nums;
    vector<vector<int>> graph;
    void update(vector<int>& list, int node)
    {
        for(auto& it : list)
        {
            res[it] = node;
        }
    }
    map<int, vector<int>> dfs(int node, int par)
    {
        map<int, vector<int>> curr;
        for(auto& nei : graph[node])
        {
            if(nei == par) continue;
            auto it = dfs(nei, node);
            if(it.size() > curr.size()) swap(it, curr);
            for(auto& i : it)
            {
                curr[i.first].insert(curr[i.first].end(), begin(i.second), end(i.second));
            }
        }
        for(auto it = begin(curr); it != end(curr);)
        {
            if(gcd(it->first, nums[node]) == 1)
            {
                update(it->second, node);
                it = curr.erase(it);
            }
            else it++;
        }
        curr[nums[node]].push_back(node);
        return curr;
    }
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        this->nums = nums;
        res.resize(n, -1), graph.resize(n);
        for(auto& edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        } 
        dfs(0, -1);
        return res;
    }
};