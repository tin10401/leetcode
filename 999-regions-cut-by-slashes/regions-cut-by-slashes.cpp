class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> board(3 * m, vector<int>(3 * n));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int r = 3 * i, c = 3 * j;
                if(grid[i][j] == '\\') board[r][c] = board[r + 1][c + 1] = board[r + 2][c + 2] = 1;
                else if(grid[i][j] == '/') board[r + 2][c] = board[r + 1][c + 1] = board[r][c + 2] = 1;
            }
        }
        auto dfs = [&](int row, int col, auto& dfs) -> void
        {
            if(row < 0 || col < 0 || row == 3 * m || col == 3 * n || board[row][col] == 1) return;
            board[row][col] = 1;
            dfs(row + 1, col, dfs);
            dfs(row - 1, col, dfs);
            dfs(row, col + 1, dfs);
            dfs(row, col - 1, dfs);
        };

        int res = 0;
        for(int i = 0; i < m * 3; i++)
        {
            for(int j = 0; j < n * 3; j++)
            {
                if(board[i][j] == 0)
                {
                    res++;
                    dfs(i, j, dfs);
                }
            }
        }
        return res;
    }
};