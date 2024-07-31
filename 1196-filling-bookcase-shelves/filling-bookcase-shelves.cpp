class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        int dp[n + 1];
        fill(dp, dp + n + 1, 1e8);
        dp[n] = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            int currWidth = shelfWidth, maxHeight = 0;
            for(int j = i; j < n; j++)
            {
                currWidth -= books[j][0];
                maxHeight = max(maxHeight, books[j][1]);
                if(currWidth < 0) break;
                dp[i] = min(dp[i], maxHeight + dp[j + 1]);
            }
        }
        return dp[0]; 
    }
};