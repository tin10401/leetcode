class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int x, int v) {
        multiset<pair<int, int>> s;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i >= x + 1) s.erase(s.find({nums[i - x - 1], i - x - 1}));
            auto it = s.upper_bound({nums[i], i});
            if(it != end(s))
            {
                if(abs(it->first - nums[i]) <= v) return true;
            } 
            if(it != begin(s))
            {
                it--;
                if(abs(it->first - nums[i]) <= v) return true;
            }
            s.insert({nums[i], i});
        }
        return false;
    }
};