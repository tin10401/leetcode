class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        for(int i = 0; i < m / 2; i++)
        {
            for(int j = 0; j < n / 2; j++)
            {
                int cnt = grid[i][j] + grid[i][n - j - 1] + grid[m - i - 1][j] + grid[m - i - 1][n - j - 1];
                res += min(cnt, 4 - cnt);
            }
        } 
        int ones = 0, cnt = 0;
        if(n & 1)
        {
            for(int i = 0; i < m / 2; i++)
            {
                cnt += grid[i][n / 2] != grid[m - i - 1][n / 2];
                ones += grid[i][n / 2] + grid[m - i - 1][n / 2];        
            }
        }
        if(m & 1)
        {
            for(int i = 0; i < n / 2; i++)
            {
                cnt += grid[m / 2][i] != grid[m / 2][n - i - 1];
                ones += grid[m / 2][i] + grid[m / 2][n - i - 1];
            }
        }
        ones %= 4;
        res += max(cnt, min(ones, 4 - ones));
        if(m % 2 && n % 2 && grid[m / 2][n / 2]) res++;
        return res;
    }
};