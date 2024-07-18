class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        using ll = long long;
        int n = nums.size();
        ll mod = 1e9 + 7, res = 0;
        vector<ll> prefix(n + 1);
        for(int i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + nums[i - 1];
        for(int i = 1; i < n; i++)
        {
            int left = i + 1, right = n - 1, leftMost = -1;
            while(left <= right)
            {
                int middle = left + (right - left) / 2;
                if(prefix[middle] - prefix[i] >= prefix[i]) leftMost = middle, right = middle - 1;
                else left = middle + 1;
            }
            if(leftMost == -1) continue;
            left = leftMost, right = n - 1;
            int rightMost = -1;
            while(left <= right)
            {
                int middle = left + (right - left) / 2;
                if(prefix[n] - prefix[middle] >= prefix[middle] - prefix[i])
                {
                    rightMost = middle;
                    left = middle + 1;
                }
                else right = middle - 1;
            }
            if(rightMost == -1) continue;
            res = (res + rightMost - leftMost + 1) % mod;
        }
        return res;
        
    }
};