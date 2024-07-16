class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
       using ll = long long;
       ll res = 0, total = 0;
       for(int right = 0, left = 0; right < nums.size(); right++)
       {
            total += nums[right];
            while(total * (right - left + 1) >= k)
            {
                total -= nums[left++];
            }
            res += right - left + 1;
       }
       return res;
    }
};