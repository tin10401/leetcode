class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> minHeap;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        minHeap.push({0, 0, 0});
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!minHeap.empty())
        {
            auto [cost, r, c] = minHeap.top();
            minHeap.pop();
            if(r == m - 1 && c == n - 1) return cost;
            if(vis[r][c]) continue;
            vis[r][c] = true;
            for(int i = 0; i < dirs.size(); i++)
            {
                int row = dirs[i][0] + r;
                int col = dirs[i][1] + c;
                if(row >= 0 && col >= 0 && row < m && col < n && !vis[row][col])
                {
                    int newCost = cost + (grid[r][c] != i + 1);
                    minHeap.push({newCost, row, col});
                }
            }
        }
        return -1;
    }
};