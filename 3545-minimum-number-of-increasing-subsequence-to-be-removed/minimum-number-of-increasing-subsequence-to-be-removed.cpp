class Solution {
public:
    int minOperations(vector<int>& nums) {
        reverse(begin(nums), end(nums));
        vector<int> prev;
        for(auto& num : nums) {
            auto it = upper_bound(begin(prev), end(prev), num);
            if(it == end(prev)) prev.push_back(num);
            else *it = num;
        } 
        return prev.size();
    }
};