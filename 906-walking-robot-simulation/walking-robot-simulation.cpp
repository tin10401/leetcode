class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        set<pair<int, int>> vis;
        for(auto& it : obstacles) vis.insert({it[0], it[1]});
        long long curr = 0, res = 0, row = 0, col = 0;
        for(auto& com : commands)
        {
            if(com == -1) curr = (curr + 1) % 4;
            else if(com == -2) curr = (curr + 3) % 4;
            else
            {
                while(!vis.count({row + dirs[curr][0], col + dirs[curr][1]}) && com--)
                {
                    row += dirs[curr][0], col += dirs[curr][1];
                }
                res = max(res, (long long)row * row + col * col);
            }
        }
        return res;
    }
};