class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        unordered_set<int> s(begin(nums), end(nums));
        int res = 0, maxi = *max_element(begin(nums), end(nums));
        for(int i = 1; i <= maxi; i++)
        {
            int curr = 0;
            for(int x = i; x <= maxi; x += i)
            {
                if(s.count(x))
                {
                    curr = gcd(curr, x);
                    if(curr == i) 
                    {
                        res++;
                        break;
                    }
                }
            }
        }
        return res;
    }
};