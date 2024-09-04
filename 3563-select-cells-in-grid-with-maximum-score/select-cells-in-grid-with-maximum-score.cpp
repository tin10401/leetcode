pair<int, int> dp[1 << 10];  // Store the maximum score and the smallest value used
class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            sort(rbegin(grid[i]), rend(grid[i]));  // Sort each row in descending order
        } 
        int res = 0;
        dp[0] = {0, 101};  // Initialize with empty set

        for (int mask = 1; mask < (1 << n); mask++) {
            auto& curr = dp[mask];
            curr = {0, 0};  // Initialize the current dp state
            set<int> used_values;  // Track the used values for uniqueness

            for (int i = 0; i < n; i++) {
                if ((mask >> i) & 1) {  // If the ith row is included in the subset
                    auto [sm, w] = dp[mask ^ (1 << i)];
                    for (int j = 0; j < m; j++) {
                        if (grid[i][j] < w && used_values.find(grid[i][j]) == used_values.end()) {
                            // If the value is smaller than the previous one and hasn't been used
                            sm += grid[i][j];
                            used_values.insert(grid[i][j]);  // Mark as used
                            w = grid[i][j];
                            break;     
                        } 
                    }
                    curr = max(curr, make_pair(sm, w));  // Update the current dp state
                }
            } 
            res = max(res, curr.first);  // Track the maximum score
        }
        return res;
    }
};
