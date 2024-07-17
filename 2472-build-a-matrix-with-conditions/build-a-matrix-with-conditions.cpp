class Solution {
public:
    vector<int> dfs(vector<vector<int>>& graph, vector<int>& degree)
    {
        queue<int> q;
        for(int i = 1; i < degree.size(); i++)
        {
            if(degree[i] == 0) q.push(i);
        }
        vector<int> res;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(auto& nei : graph[node])
            {
                if(--degree[nei] == 0) q.push(nei);
            }
        }
        return res.size() == degree.size() - 1 ? res : vector<int>();
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> rowGraph(k + 1), colGraph(k + 1);
        vector<int> rowDegree(k + 1), colDegree(k + 1);
        for(auto& r : rowConditions)
        {
            rowGraph[r[0]].push_back(r[1]);
            rowDegree[r[1]]++;
        }
        for(auto& c : colConditions)
        {
            colGraph[c[0]].push_back(c[1]);
            colDegree[c[1]]++;
        }
        auto rowOrder = dfs(rowGraph, rowDegree), colOrder = dfs(colGraph, colDegree);
        if(rowOrder.empty() || colOrder.empty()) return {};
        vector<vector<int>> pos(k + 1, vector<int>(k + 1, -1));
        for(int i = 0; i < k; i++)
        {
            pos[rowOrder[i]][0] = i;
            pos[colOrder[i]][1] = i;
        }
        vector<vector<int>> matrix(k, vector<int>(k));
        for(int i = 1; i <= k; i++)
        {
            matrix[pos[i][0]][pos[i][1]] = i;
        }
        return matrix;
    }
};