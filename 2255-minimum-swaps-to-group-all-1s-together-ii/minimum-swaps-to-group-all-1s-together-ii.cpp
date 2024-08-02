class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int one = count(nums.begin(), nums.end(), 1);
        int res = count(nums.begin(), nums.begin() + one, 0);
        int n = nums.size(), curr = res;
        for(int i = 0, j = one; j < 2 * n; i++, j++)
        {
            if(nums[j % n] == 0) curr++;
            if(nums[i % n] == 0) curr--;
            res = min(res, curr);
        }
        return res;
    }
};