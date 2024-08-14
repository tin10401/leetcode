class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0, right = nums.back() - nums.front();

        auto countPairs = [&](int mid) -> int {
            int count = 0;
            int j = 0;
            for (int i = 0; i < n; i++) {
                while (j < n && nums[j] - nums[i] <= mid) {
                    j++;
                }
                count += (j - i - 1);
            }
            return count;
        };

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (countPairs(mid) < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
