const int MX = 2001;
int dp[MX][MX], a[MX][MX];
class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            a[i][0] = dp[i][0] = nums[i];
        }
        for(int d = 1; d <= n; d++) {
            for(int i = 0; i < n; i++) {
                if(i + d >= n) break;
                a[i][d] = a[i][d - 1] ^ a[i + 1][d - 1]; 
                dp[i][d] = max({dp[i][d - 1], dp[i + 1][d - 1], a[i][d]});
            }
        }
        vector<int> res;
        for(auto& it : queries) {
            int left = it[0], right = it[1];
            int len = right - left;
            res.push_back(dp[left][len]);
        }
        return res;
    }
};