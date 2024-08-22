class Solution {
public:
    int findComplement(int num) {
        int temp = num;
        int index = 0;
        while(temp)
        {
            num ^= (1 << index++);
            temp >>= 1;
        }
        return num;
    }
};