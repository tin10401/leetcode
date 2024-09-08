class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long res = 0, mx = INT_MIN;
        for(auto& it : nums) {
            mx = fmax(mx, it);
            res += mx;
        }
        return res - mx;
    }
};