class Solution {
public:
    int findComplement(int num) {
        int msb = log2(num);
        return ~num & ((1 << (msb)) - 1); 
    }
};