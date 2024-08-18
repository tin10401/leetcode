class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        auto f = board, g = board;
        using ll = long long;
        ll res = -1e15;
        int m = board.size(), n = board[0].size();
        for(int i = 1; i < m; i++)
        {
            for(int j = 0; j < n; j++) f[i][j] = max(f[i][j], f[i - 1][j]);
        }
        for(int i = m - 2; i >= 0; i--)
        {
            for(int j = 0; j < n; j++) g[i][j] = max(g[i][j], g[i + 1][j]);
        }
        for(int i = 1; i < m - 1; i++)
        {
            set<pair<int, int>> up, dw;
            for(int j = 0; j < n; j++)
            {
                up.insert({f[i - 1][j], j});
                if(up.size() > 3) up.erase(begin(up));
                dw.insert({g[i + 1][j], j});
                if(dw.size() > 3) dw.erase(begin(dw));
            }
            for(int j = 0; j < n; j++)
            {
                for(auto& [x1, j1] : up)
                {
                    for(auto& [x2, j2] : dw)
                    {
                        if(j1 == j || j1 == j2 || j == j2) continue;
                        res = max(res, (ll)x1 + x2 + board[i][j]);
                    }
                }
            }
        }
        return res;
    }
};