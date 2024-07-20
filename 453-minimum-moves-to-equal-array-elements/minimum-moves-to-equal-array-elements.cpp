class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        int x = nums[0];
        int res = 0;
        for(auto& num : nums) 
        {
            res += abs(num - x);
        }
        return res ;
    }
};