class Solution {
public:
    int minimumDeletions(string s) {
        int res = 0;
        int count = 0;
        for(char& ch : s)
        {
            if(ch == 'b') count++;
            else res = min(res + 1, count);
        }
        return res;
    }
};