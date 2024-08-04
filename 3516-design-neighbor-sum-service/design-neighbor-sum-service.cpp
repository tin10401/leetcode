class neighborSum {
public:
    int m, n;
    vector<vector<int>> grid;
    unordered_map<int, pair<int, int>> list;
    neighborSum(vector<vector<int>>& grid) {
        this->grid = grid;
        m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                list[grid[i][j]] = {i, j};
            }
        }
    }
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int adjacentSum(int value) {
        int res = 0;
        auto [r, c] = list[value];
        for(auto& dir : dirs)
        {
            int row = r + dir[0], col = c + dir[1];
            if(row >= 0 && col >= 0 && row < m && col < n) res += grid[row][col];
        }
        return res;
    }
    vector<vector<int>> din = {{-1, -1}, {1, 1}, {-1, 1}, {1, -1}}; 
    int diagonalSum(int value) {
        int res = 0;
        auto [r, c] = list[value];
        for(auto& dir : din)
        {
            int row = r + dir[0], col = c + dir[1];
            if(row >= 0 && col >= 0 && row < m && col < n) res += grid[row][col];
        }
        return res;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */