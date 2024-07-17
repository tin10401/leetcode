class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& r) {
        r.insert(end(r), {{1, 0}, {n, n - 1}});
        sort(begin(r), end(r));
        int res = 0;
        int m = r.size();
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
            int currId = r[i][0], currHeight = r[i][1];
            int nextId = r[i + 1][0], nextHeight = r[i + 1][1];
            int d = nextId - currId;
            int maxHeight = (currHeight + nextHeight + d) / 2;
            res = max(res, maxHeight);
        }
        return res;
    }
};