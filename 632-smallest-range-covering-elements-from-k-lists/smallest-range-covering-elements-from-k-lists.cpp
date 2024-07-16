class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        multiset<array<int, 3>> s;
        int left = INT_MAX, right = INT_MIN;
        for(int i = 0; i < nums.size(); i++)
        {
            s.insert({nums[i][0], 1, i});
            left = min(left, nums[i][0]);
            right = max(right, nums[i][0]);
        }
        int len = right - left;
        while(s.size() > 1)
        {
            auto leftRange = s.begin();
            auto [num, index, i] = *leftRange;
            s.erase(leftRange);
            auto rightRange = prev(s.end());
            if((*rightRange)[0] - num < len)
            {
                len = (*rightRange)[0] - num;
                left = num, right = (*rightRange)[0];
            }
            if(index >= nums[i].size()) break;
            s.insert({nums[i][index], index + 1, i});
        }
        return {left, right};
    }
};