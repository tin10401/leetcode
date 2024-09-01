int dp[1 << 11][12][12];
class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++) {
            sort(rbegin(grid[i]), rend(grid[i]));
        } 
        memset(dp, -1, sizeof(dp)); 
        auto dfs = [&](auto& dfs, int mask = 0, int row = 11, int col = 11) -> int {
            int& best = dp[mask][row][col];
            if(best != -1) return best;
            best = 0;
            for(int i = 0; i < n; i++) {
                if((mask >> i) & 1) continue;
                for(int j = 0; j < m; j++) {
                    if(row == 11 || grid[i][j] < grid[row][col]) {
                        best = max(best, grid[i][j] + dfs(dfs, mask | (1 << i), i, j));
                        break;
                    }
                }
            }   
            return best;
        };
        return dfs(dfs);
    }
};