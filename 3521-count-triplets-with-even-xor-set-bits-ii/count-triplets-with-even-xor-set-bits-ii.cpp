class Solution {
public:
    long long tripletCount(vector<int>& a, vector<int>& b, vector<int>& c) {
        using ll = long long;
        ll bits[3][2] = {};
        for(auto& num : a)
        {
            bits[0][__builtin_popcount(num) % 2]++;
        }
        for(auto& num : b)
        {
            bits[1][__builtin_popcount(num) % 2]++;
        }
        for(auto& num : c)
        {
            bits[2][__builtin_popcount(num) % 2]++;
        }
        ll res = 
        bits[0][0] * bits[1][0] * bits[2][0] + 
        bits[0][0] * bits[1][1] * bits[2][1] + 
        bits[0][1] * bits[1][1] * bits[2][0] + 
        bits[0][1] * bits[1][0] * bits[2][1];
        return res;
    }
};