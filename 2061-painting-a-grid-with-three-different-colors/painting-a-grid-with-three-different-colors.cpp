int dp[1001][6][1036][4];
class Solution {
public:
    vector<vector<int>> grid;
    int mod = 1e9 + 7, m, n;
    int getMask(int row)
    {
        int mask = 0;
        for(int i = 0; i < m; i++)
        {
            mask |= ((grid[row][i] << (2 * i)));
        }
        return mask;
    }
    int dfs(int row, int col)
    {
        if(row == n) return 1;
        if(col == m) return dfs(row + 1, 0);
        int prev = col == 0 ? 0 : grid[row][col - 1];
        int mask = row == 0 ? 0 : getMask(row - 1);
        int res = dp[row][col][mask][prev];
        if(col == 0 && res != -1) return res;
        res = 0;
        int upper = row == 0 ? 0 : grid[row - 1][col];
        for(int i = 1; i <= 3; i++)
        {
            if(i != upper && i != prev)
            {
                grid[row][col] = i;
                res = (res + dfs(row, col + 1)) % mod;
                grid[row][col] = 0;
            }
        }
        if(col == 0) dp[row][col][mask][prev] = res;
        return res;
    }
    int colorTheGrid(int m, int n) {
        memset(dp, -1, sizeof(dp));
        grid.resize(n, vector<int>(m, 0));
        this->m = m, this->n = n;
        return dfs(0, 0);
    }
};