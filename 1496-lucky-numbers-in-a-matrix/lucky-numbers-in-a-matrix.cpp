class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> col(n, 0);
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n ; j++)
            {
                col[j] = max(col[j], matrix[i][j]);
            }
        }
        vector<int> res;
        for(int i = 0; i < m; i++)
        {
            int temp = min_element(matrix[i].begin(), matrix[i].end()) - matrix[i].begin();
            if(matrix[i][temp] == col[temp])
            {
                res.push_back(col[temp]);
            }
        }
        return res;
    }
};