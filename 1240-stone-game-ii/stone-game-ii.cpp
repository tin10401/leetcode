class Solution {
public:
    vector<vector<vector<int>>> dp;
    // int dp[10001][10001][2];
    int dfs(int start, int M, bool turn, vector<int>& piles)
    {
        if(start >= piles.size())
        {
            return 0;
        }
        if(dp[start][M][turn] != -1)
        {
            return dp[start][M][turn];
        }
        int res = turn ? 0 : INT_MAX;
        int range = 2 * M + 1;
        int sum = 0;
        for(int i = 1; i < range; i++)
        {
            if(i + start > piles.size())
            {
                break;
            }
            sum += piles[start + i - 1];
            if(turn)
            {
                res = max(res, sum + dfs(start + i, max(M, i), !turn, piles));
            }
            else
            {
                res = min(res, dfs(start + i, max(M, i), !turn, piles));
            }
        }
        return dp[start][M][turn] = res;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        dp.assign(n, vector<vector<int>>(n + 1, vector<int>(2, -1)));
        return dfs(0, 1, true, piles);
    }
};