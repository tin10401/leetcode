class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(m * n != original.size())
        {
            return {};
        }
        vector<vector<int>> res;
        int count = 0;
        vector<int> curr;
        for(int num : original)
        {
            count++;
            curr.push_back(num);
            if(count == n)
            {
                res.push_back(curr);
                count = 0;
                curr.clear();
            }
        }
        return res;
    }
};