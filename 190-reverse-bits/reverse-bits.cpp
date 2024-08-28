class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int res = 0;
        for(int i = 0; i < 32; i++)
        {
            long long bits = (n >> i) & 1;
            res |= (bits << (32 - i - 1));
        }
        return res;
    }
};