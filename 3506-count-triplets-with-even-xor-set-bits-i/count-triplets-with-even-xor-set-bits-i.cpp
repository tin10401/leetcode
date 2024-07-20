class Solution {
public:
    int tripletCount(vector<int>& a, vector<int>& b, vector<int>& c) {
        int res = 0;
        for(int i = 0; i < a.size(); i++)
        {
            for(int j = 0; j < b.size(); j++)
            {
                for(int k = 0; k < c.size(); k++)
                {
                    int num = a[i] ^ b[j] ^ c[k];
                    res += __builtin_popcount(num) % 2 == 0;
                }
            }
        }
        return res;
    }
};