class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long res = 0;
        int mx = INT_MIN;
        for(auto& it : nums) {
            mx = max(mx, it);
            res += mx;
        }
        res -= mx;
        return res;
    }
};