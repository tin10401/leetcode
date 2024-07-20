class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        set<vector<vector<int>>> vis;
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        auto compute = [](vector<vector<int>>& grid)
        {
            pair<int, int> p;
            for(int i = 0; i < 2; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    if(grid[i][j] == 0)
                    {
                        p = {i, j};
                    }
                }
            }
            return p;
        };
        queue<vector<vector<int>>> q;
        vector<vector<int>> target = {{1, 2, 3}, {4, 5, 0}};
        q.push(board);
        vis.insert(board);
        int res = 0;
        while(!q.empty())
        {
            int size = q.size();
            res++;
            while(size--)
            {
                auto grid = q.front(); q.pop();
                if(grid == target) return res - 1;
                auto [r, c] = compute(grid);
                for(auto& dir : dirs)
                {
                    int row = r + dir[0], col = c + dir[1];
                    if(row >= 0 && col >= 0 && row < 2 && col < 3)
                    {
                        swap(grid[row][col], grid[r][c]);
                        if(grid == target) return res;
                        if(!vis.count(grid))
                        {
                            vis.insert(grid);
                            q.push(grid);
                        }
                        swap(grid[row][col], grid[r][c]);
                    }
                }

            }
        }
        return -1;
    }
};