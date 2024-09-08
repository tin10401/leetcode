class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long res = 0, mx = INT_MIN;
        for(auto& it : nums) {
            res += mx = fmax(mx, it);
        }
        return res - mx;
    }
};