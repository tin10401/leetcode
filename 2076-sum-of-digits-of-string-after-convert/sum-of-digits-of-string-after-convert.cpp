class Solution {
public:
    int getLucky(string s, int k) {
        string transform = "";
        for(auto& ch : s)
        {
            transform += to_string(ch - 'a' + 1);
        }
        while(k-- > 0)
        {
            int count = 0;
            for(auto& ch : transform)
            {
                count += ch - '0';
            }
            if(k == 0)
            {
                return count;
            }
            transform = to_string(count);
        }
        return 0;
    }
};