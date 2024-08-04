class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(int i = 0; i < n; i++) minHeap.push({nums[i], i + 1});
        int res = 0, mod = 1e9 + 7;
        for(int i = 1; i <= right; i++)
        {
            auto [val, index] = minHeap.top();
            minHeap.pop();
            if(i >= left) res = (res + val) % mod;
            if(index < n)
            {
                val += nums[index++];
                minHeap.push({val, index});
            }
        }
        return res;
    }
};