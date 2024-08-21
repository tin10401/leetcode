class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size(), n = strs[0].size(), res = 0, i = 0;
        vector<bool> sorted(n, false);
        for(int j = 0; j < n; j++)
        {
            bool ok = true;
            for(i = 0; i < m - 1; i++)
            {
                if(!sorted[i] && strs[i][j] > strs[i + 1][j])
                {
                    ok = false;
                    res++;
                    break;
                }
            }
            if(!ok) continue;
            for(int i = 0; i < m - 1; i++)
            {
                if(strs[i][j] < strs[i + 1][j]) sorted[i] = true;
            }
        }
        return res;
    }
};