class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> list;
        for(int i = 0; i < n; i++)
        {
            if(nums[i]) list.push_back(i);
        }    
        using ll = long long;
        ll median = k / 2;
        ll total = 0;
        ll res = INT_MAX;
        vector<ll> prefix(list.size() + 1);
        for(int i = 1; i <= list.size(); i++) prefix[i] = prefix[i - 1] + list[i - 1];
        for(int i = k - 1; i < list.size(); i++)
        {
            ll rightBound = list[median] + k / 2 - (k % 2 == 0);
            ll leftBound = list[median] - 1;
            ll leftSum = prefix[median] - prefix[i - k + 1];
            ll leftSum2 = leftBound * (leftBound + 1) / 2 - (rightBound - k + 1) * (rightBound - k) / 2;
            ll rightSum = prefix[i + 1] - prefix[median + 1];
            ll rightSum2 = (rightBound + 1) * rightBound / 2 - ((ll)list[median] + 1) * list[median] / 2;
            res = min(res, leftSum2 - leftSum + rightSum - rightSum2);
            median++;
        }
        return res;
    }
};