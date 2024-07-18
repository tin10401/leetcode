class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        using ll = long long;
        set<int> s;
        for(auto& num : nums1) s.insert(num);
        ll right = 0, n = nums1.size(), mod = 1e9 + 7;
        for(int i = 0; i < n; i++)
        {
            right += abs(nums1[i] - nums2[i]);
        }
        ll res = right, left = 0;
        for(int i = 0; i < n; i++)
        {
            right -= abs(nums1[i] - nums2[i]);
            auto it = s.lower_bound(nums2[i]);
            if(it != end(s))
            {
                res = min(res, left + right + abs(*it - nums2[i]));
            }
            if(it != begin(s))
            {
                it--;
                res = min(res, left + right + abs(*it - nums2[i]));
            }
            left += abs(nums1[i] - nums2[i]);
        }
        return res % mod;
    }
};