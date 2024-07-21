class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        using ll = long long;
        ll hash = 0, currPow = 1, start = 0;
        for(int i = 0; i < k; i++) currPow = (currPow * power) % modulo;
        for(int i = s.size() - 1; i >= 0; i--)
        {
            hash = (hash * power + s[i] - 'a' + 1) % modulo;
            if(i + k <= s.size())
            {
                if(i + k <= s.size() - 1) hash = (hash - (s[i + k] - 'a' + 1) * currPow % modulo + modulo) % modulo;
                if(hash == hashValue) start = i;
            }
        }
        return s.substr(start, k);
    }   
};