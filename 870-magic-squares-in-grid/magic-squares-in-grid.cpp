class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        auto check = [&](int r, int c)
        {
            int vis = 0;
            int row[3] = {}, col[3] = {};
            for(int i = r; i < r + 3; i++)
            {
                for(int j = c; j < c + 3; j++)
                {
                    int val = grid[i][j];
                    if(val > 9 || val < 1 || (vis >> val) & 1) return false;
                    vis |= (1 << val);
                    row[i % 3] += val;
                    col[j % 3] += val;
                }
            }
            int diagnal = grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2];
            int anti = grid[r + 2][c] + grid[r + 1][c + 1] + grid[r][c + 2];
            return row[0] == row[1] && row[0] == row[2] && col[0] == col[1] && col[0] == col[2] && row[0] == diagnal && anti == row[0];
        };
        int m = grid.size(), n = grid[0].size(), res = 0;
        for(int i = 0; i < m - 2; i++)
        {
            for(int j = 0; j < n - 2; j++)
            {
                res += check(i, j);
            }
        }
        return res;
    }
    
};