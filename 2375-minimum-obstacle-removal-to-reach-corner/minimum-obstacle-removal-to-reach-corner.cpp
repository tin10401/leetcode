class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> minHeap;
        int m = grid.size(), n = grid[0].size();
        bool vis[m][n];
        memset(vis, false, sizeof(vis));
        minHeap.push({0, 0, 0});
        while(!minHeap.empty())
        {
            auto [cost, r, c] = minHeap.top();
            minHeap.pop();
            if(r == m - 1 && c == n - 1) return cost;
            if(vis[r][c]) continue;
            vis[r][c] = true;
            for(auto& dir : dirs)
            {
                int row = r + dir[0];
                int col = c + dir[1];
                if(row >= 0 && col >= 0 && row < m && col < n && !vis[row][col])
                {
                    int newCost = cost + grid[row][col];
                    minHeap.push({newCost, row, col});
                }
            }
        }
        return -1;
    }
};