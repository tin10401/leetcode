class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++) {
            sort(rbegin(grid[i]), rend(grid[i]));
        } 
        auto dfs = [&](auto& dfs, int mask = 0, int last = 101) -> int {
            int best = 0;
            for(int i = 0; i < n; i++) {
                if((mask >> i) & 1) continue;
                for(int j = 0; j < m; j++) {
                    if(grid[i][j] < last) {
                        best = max(best, grid[i][j] + dfs(dfs, mask | (1 << i), grid[i][j]));
                        break;
                    }
                }
            }   
            return best;
        };
        return dfs(dfs);
    }
};