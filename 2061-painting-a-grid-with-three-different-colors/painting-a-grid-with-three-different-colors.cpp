class Solution {
public:
    int dp[1001][1034], m, n, mod = 1e9 + 7;
    int setMask(int mask, int val, int index)
    {
        return mask | (val << (2 * index));
    }
    int getMask(int mask, int index)
    {
        return (mask >> (2 * index)) & 3;
    }
    int dfs(int row, int col, int prevMask, int currMask)
    {
        if(row == n) return 1;
        if(col == m) return dfs(row + 1, 0, currMask, 0);
        if(col == 0 && dp[row][prevMask] != -1) return dp[row][prevMask];
        int res = 0;
        for(int i = 1; i <= 3; i++)
        {
            if(i != getMask(prevMask, col) && (col == 0 || i != getMask(currMask, col - 1)))
            {
                res = (res + dfs(row, col + 1, prevMask, setMask(currMask, i, col))) % mod;
            }
        }
        if(col == 0) dp[row][prevMask] = res;
        return res;
    }


    int colorTheGrid(int m, int n) {
        memset(dp, -1, sizeof(dp));
        this->m = m, this->n = n;
        return dfs(0, 0, 0, 0);
    }
};