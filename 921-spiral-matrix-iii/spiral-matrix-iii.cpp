class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int r, int c) {
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int step = 1, i = 0;
        vector<vector<int>> res;
        while(res.size() < rows * cols)
        {
            for(int j = 0; j < 2; j++)
            {
                for(int y = 0; y < step; y++)
                {
                    if(r >= 0 && r < rows && c >= 0 && c < cols)
                    {
                        res.push_back({r, c});
                    }
                    r += dirs[i][0], c += dirs[i][1];
                }
                i = (i + 1) % 4;
            }
            step++;
        } 
        return res;
    }
};