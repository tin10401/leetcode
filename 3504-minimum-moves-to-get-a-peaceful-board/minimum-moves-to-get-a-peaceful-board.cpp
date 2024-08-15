class Solution {
public:
    int minMoves(vector<vector<int>>& rooks) {
        sort(begin(rooks), end(rooks));
        int res = 0, n = rooks.size();
        for(int i = 0; i < n; i++)
        {
            res += abs(i - rooks[i][0]);
        }
        auto compare = [](const vector<int>& a, const vector<int>& b)
        {
            return a[1] < b[1];
        };
        sort(begin(rooks), end(rooks), compare);
        for(int i = 0; i < n; i++)
        {
            res += abs(i - rooks[i][1]);
        }
        return res;
    }
};