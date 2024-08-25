class Solution {
public:
    int countPairs(vector<int>& nums) {
        int n = nums.size();
        int cnt[n][10];
        auto isValid = [&](int a, int b) -> bool
        {
            int c = 0;
            string t1 = to_string(a), t2 = to_string(b);
            if(t1.size() > t2.size()) swap(t1, t2);
            t1 = string(t2.size() - t1.size(), '0') + t1;
            string a1, a2;
            for(int i = 0; i < t2.size(); i++)
            {
                if(t1[i] != t2[i])
                {
                    a1 += t1[i];
                    a2 += t2[i];
                }
            }
            if(a1.size() > 3 || a1.size() % 2) return false;
            sort(a1.begin(), a1.end()), sort(a2.begin(), a2.end());
            return a1 == a2;
        };
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < n; i++)
        {
            int num = nums[i];
            while(num)
            {
                cnt[i][num % 10]++;
                num /= 10;
            }
        } 
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                res += isValid(nums[i], nums[j]);
        }
        }
        return res;
    }
};