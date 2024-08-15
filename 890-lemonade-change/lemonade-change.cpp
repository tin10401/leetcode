class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int dp[2];
        memset(dp, 0, sizeof(dp));
        for(int num : bills)
        {
            if(num == 5)
            {
                dp[0]++;
            }
            else if(num == 10)
            {
                if(--dp[0] < 0)
                {
                    return false;
                }
                dp[1]++;
            }
            else
            {
                if(dp[1] == 0)
                {
                    if(dp[0] < 3)
                    {
                        return false;
                    }
                    dp[0] -= 3;
                }
                else
                {
                    dp[1]--;
                    if(--dp[0] < 0)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }   
};