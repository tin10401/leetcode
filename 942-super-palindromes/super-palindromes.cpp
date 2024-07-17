class Solution {
public:
    int superpalindromesInRange(string l, string r) {
        using ll = unsigned long long;
        ll left = stoll(l), right = stoll(r), res = 0;
        auto isValid = [&](ll num)
        {
            ll next = 0, curr = num;
            while(num)
            {
                next = next * 10 + num % 10;
                num /= 10;
            }
            return curr == next;
        };
        auto transform = [&](ll curr, ll num)
        {
            ll rev = 0, base = 1;
            while(num)
            {
                rev = rev * 10 + num % 10;
                base *= 10;
                num /= 10;
            }
            return curr * base + rev;
        };
        for(int i = 1; i <= 1e5; i++)
        {   
            ll curr = transform(i, i / 10);
            curr *= curr;
            if(curr >= left && curr <= right && isValid(curr)) res++;
            if(curr > right) break;
            curr = transform(i, i);
            curr *= curr;
            if(curr >= left && curr <= right && isValid(curr)) res++;
        }
        return res;
    }
};