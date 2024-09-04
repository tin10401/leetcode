pair<int, int> dp[1 << 10];
class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++) {
            sort(rbegin(grid[i]), rend(grid[i]));
        } 
        int res = 0;
        dp[0] = {0, 101};
        for(int mask = 1; mask < (1 << n); mask++) {
            auto& curr = dp[mask];
            curr = {0, 0};
            for(int i = 0; i < n; i++) {
                if((mask >> i) & 1) {
                    auto [sm, w] = dp[mask ^ (1 << i)];
                    for(int j = 0; j < m; j++) {
                        if(grid[i][j] < w) {
                            sm += grid[i][j];
                            w = grid[i][j]; 
                            break;     
                        } 
                    }
                    
                    curr = max(curr, make_pair(sm, w));
                }
            } 
            res = max(res, curr.first);
        }
        return res;
    }
};