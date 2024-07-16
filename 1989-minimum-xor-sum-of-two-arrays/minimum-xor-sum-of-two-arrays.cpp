class Solution {
public:
    using ll = long long;
    ll dp[15][1 << 14 + 1];
    ll dfs(int index, int mask)
    {
        if(mask == 0) return 0;
        ll& res = dp[index][mask];
        if(res != -1) return res;
        res = INT_MAX;
        for(int i = 0; i < nums2.size(); i++)
        {
            if((mask >> i) & 1)
            {
                res = min(res, (nums1[index] ^ nums2[i]) + dfs(index + 1, mask ^ (1 << i)));
            }
        }  
        return res;
    }
    vector<int> nums1, nums2;
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof(dp));
        int n = nums1.size();
        this->nums1 = nums1, this->nums2 = nums2;
        return dfs(0, (1 << n) - 1);
    }
};