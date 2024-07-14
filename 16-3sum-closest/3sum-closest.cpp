class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // solution
        sort(nums.begin(), nums.end());
        int res = INT_MAX;
        int size = nums.size();
        int minDiff = INT_MAX;
        for(int i = 0; i < size; i++)
        {
            if(i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int left = i + 1;
            int right = size - 1;
            while(left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == target)
                {
                    return target;
                }
                int diff = abs(sum - target);
                if(diff < minDiff)
                {
                    minDiff = diff;
                    res = sum;
                }
                if(sum > target)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
        return res;
    }
};