class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& r) {
        r.insert(end(r), {{1, 0}, {n, n - 1}});
        sort(begin(r), end(r));
        int res = 0, m = r.size();
        for(int i = 1; i < m; i++)
        {
            r[i][1] = min(r[i][1], r[i - 1][1] + r[i][0] - r[i - 1][0]);
        }
        for(int i = m - 2; i >= 0; i--)
        {
            r[i][1] = min(r[i][1], r[i + 1][1] + r[i + 1][0] - r[i][0]);
        }
        for(int i = 0; i < m - 1; i++)
        {
            int height = (r[i][1] + r[i + 1][1] + r[i + 1][0] - r[i][0]) / 2;
            res = max(res, height);
        }
        return res;
    }
};