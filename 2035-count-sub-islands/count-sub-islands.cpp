class Solution {
public:
    void dfs(int row, int col, bool& found, vector<vector<int>>& grid1, vector<vector<int>>& grid2)
    {
        if (row < 0 || col < 0 || row == grid1.size() || col == grid1[0].size() || grid2[row][col] == 0) {
            return;
        }
        if (grid2[row][col] == 1 && grid1[row][col] == 0) {
            found = false;
        }
        grid2[row][col] = 0;
        dfs(row + 1, col, found, grid1, grid2);
        dfs(row - 1, col, found, grid1, grid2);
        dfs(row, col + 1, found, grid1, grid2);
        dfs(row, col - 1, found, grid1, grid2);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int ROW = grid1.size();
        int COL = grid1[0].size();
        int res = 0;
        for(int row = 0; row < ROW; row++)
        {
            for(int col = 0; col < COL; col++)
            {
                if(grid2[row][col] == 1)
                {
                    bool found = true;
                    dfs(row, col, found, grid1, grid2);
                    if(found)
                    {
                        res++;
                    }
                }
            }
        }
        return res;
    }
};