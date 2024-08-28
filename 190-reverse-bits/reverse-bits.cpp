class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int res = 0;
        for(int i = 0; i < 32; i++)
        {
            res |= ((n >> i)  & 1) << (32 - i - 1);
        }
        return res;
    }
};