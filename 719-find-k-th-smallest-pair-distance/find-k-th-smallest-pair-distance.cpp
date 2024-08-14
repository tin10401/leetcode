class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        auto compute = [&](int m)
        {
            int total = 0;
            for(int i = 0, j = 0; i < n && total < k; i++)
            {
                while(j < n && nums[j] - nums[i] <= m) j++;
                total += j - i - 1;
            }
            return total >= k;
        };
        const int INF = INT_MAX;
        int left = 0, right = INF, res = 0;
        while(left <= right)
        {
            int middle = left + (right - left) / 2;
            if(compute(middle)) res = middle, right = middle - 1;
            else left = middle + 1;
        }
        return res;
    }
};