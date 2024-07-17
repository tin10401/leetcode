class Solution {
public:
    int dp[1001][1034], m, n, mod = 1e9 + 7;

    // Function to set a value in the mask
    int setMask(int mask, int val, int index) {
        return mask | (val << (2 * index));
    }

    // Function to get a value from the mask
    int getMask(int mask, int index) {
        return (mask >> (2 * index)) & 3;
    }

    // DFS function to calculate the number of ways to color the grid
    int dfs(int row, int col, int prevMask, int currMask) {
        if (row == n) return 1; // Base case: reached the end of the grid
        if (col == m) return dfs(row + 1, 0, currMask, 0); // Move to the next row

        if (col == 0 && dp[row][prevMask] != -1) return dp[row][prevMask]; // Memoization

        int res = 0;
        for (int i = 1; i <= 3; i++) { // Iterate over the three possible colors (1, 2, 3)
            if (i != getMask(prevMask, col) && (col == 0 || i != getMask(currMask, col - 1))) {
                res = (res + dfs(row, col + 1, prevMask, setMask(currMask, i, col))) % mod;
            }
        }

        if (col == 0) dp[row][prevMask] = res; // Memoization
        return res;
    }

    // Function to initialize and start the DFS
    int colorTheGrid(int m, int n) {
        memset(dp, -1, sizeof(dp)); // Initialize the DP array with -1
        this->m = m;
        this->n = n;
        return dfs(0, 0, 0, 0); // Start the DFS from the first cell
    }
};