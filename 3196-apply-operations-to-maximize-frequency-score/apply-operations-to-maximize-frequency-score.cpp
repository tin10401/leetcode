class Solution {
public:
    int maxFrequencyScore(vector<int>& nums, long long k) {
       sort(begin(nums), end(nums));
       int n = nums.size();
       using ll = long long;
       vector<ll> prefix(n + 1);
       for(int i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + nums[i - 1];
       auto compute = [&](int m)
       {
        for(ll median = m / 2, i = m - 1; i < n; i++, median++)
        {
           ll leftSum = nums[median] * (median - (i - m)) - (prefix[median + 1] - prefix[i - m + 1]);
           ll rightSum = abs(nums[median] * (i - median + 1) - (prefix[i + 1] - prefix[median]));
           if(leftSum + rightSum <= k) return true;
        }
        return false;
       };
       int left = 1, right = nums.size(), res = 1;
       while(left <= right)
       {
        int middle = left + (right - left) / 2;
        if(compute(middle)) res = middle, left = middle + 1;
        else right = middle - 1;
       } 
       return res;
    }
};