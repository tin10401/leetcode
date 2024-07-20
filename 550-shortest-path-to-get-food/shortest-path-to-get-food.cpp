class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == '*') {q.push({i, j}); grid[i][j] = 'X'; break;}
            }
            if(!q.empty()) break;
        }
        int res = 0;
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        while(!q.empty())
        {
            int size = q.size();
            res++;
            while(size--)
            {
                auto [r, c] = q.front(); q.pop();
                for(auto& dir : dirs)
                {
                    int row = r + dir[0], col = c + dir[1];
                    if(row >= 0 && col >= 0 && row < m && col < n && grid[row][col] != 'X')
                    {
                        if(grid[row][col] == '#') return res;
                        grid[row][col] = 'X';
                        q.push({row, col});
                    }
                }
            }
        }
        return -1;
    }
};