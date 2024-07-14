class Solution {
public:
    // solution by tinle
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        vector<vector<int>> res;
        for(int i = 0; i < size; i++)
        {
            if(i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            for(int j = i + 1; j < size; j++)
            {
                if(j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }
                int left = j + 1;
                int right = size - 1;
                while(left < right)
                {
                    long long s = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if(s == target)
                    {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while(left < right && nums[left] == nums[left + 1])
                        {
                            left++;
                        }
                        while(left < right && nums[right] == nums[right - 1])
                        {
                            right--;
                        }
                        left++;
                        right--;
                    }
                    else if(s < target)
                    {
                        left++;
                    }
                    else
                    {
                        right--;
                    }
                    
                }
            }
        }
        return res;
    }
};