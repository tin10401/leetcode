class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        using ll = long long;
        int n = nums.size(), res = INT_MAX;
        vector<ll> prefix(n + 1);
        for(int i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + nums[i - 1];
        deque<int> q;
        for(int i = 0; i <= n; i++)
        {
            while(!q.empty() && prefix[i] <= prefix[q.back()]) q.pop_back();
            while(!q.empty() && prefix[i] - prefix[q.front()] >= k) 
            {
                res = min(res, i - q.front());
                q.pop_front();
            }
            q.push_back(i);
        }
        return res == INT_MAX ? -1 : res;
    }
};