class Solution {
public:
    int dp[1001];
    vector<vector<int>> books;
    int width;
    int dfs(int index)
    {
        if(index == books.size()) return 0;
        int& res = dp[index];
        if(res != -1) return res;
        res = INT_MAX;
        int maxHeight = 0, currWidth = width;
        for(int i = index; i < books.size(); i++)
        {
            maxHeight = max(maxHeight, books[i][1]);
            currWidth -= books[i][0];
            if(currWidth < 0) break;
            res = min(res, maxHeight + dfs(i + 1));
        }
        return res;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(dp, -1, sizeof(dp));
        this->books = books;
        this->width = shelfWidth;
        return dfs(0);
        
    }
};