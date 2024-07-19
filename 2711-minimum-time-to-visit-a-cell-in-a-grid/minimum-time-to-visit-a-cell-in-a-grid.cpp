class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> minHeap;
        vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        minHeap.push({0, 0, 0});
        bool found = false;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dis(m, vector<int>(n, 1e8));
        int count = 0;
        while(!minHeap.empty())
        {
            auto [time, r, c] = minHeap.top(); minHeap.pop();
            if(r == m - 1 && c == n - 1) return time;
            for(auto& dir : dirs)
            {
                int row = r + dir[0], col = c + dir[1];
                if(row >= 0 && col >= 0 && row < m && col < n)
                {
                    int newTime = time;
                    if(grid[row][col] > time + 1)
                    {
                        if(r == 0 && c == 0 && count == 0) continue;
                        int diff = grid[row][col] - time;
                        newTime += diff + (diff % 2 == 0 ? 1 : 0);
                    }
                    else newTime++;
                    if(newTime < dis[row][col])
                    {
                        dis[row][col] = newTime;
                        minHeap.push({newTime, row, col});
                    }
                }
            }
            count++;
        }
        return -1;
    }
};