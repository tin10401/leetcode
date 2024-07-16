class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int total = accumulate(begin(arr), end(arr), 0);
        if(total % 3 != 0) return {-1, -1};
        if(total == 0) return {0, (int)arr.size() - 1};
        int target = total / 3, n = arr.size(), curr = 0, p1 = 0, p2 = 0, p3 = 0;
        for(int i = 0; i < n; i++)
        {
            curr += arr[i];
            if(curr == 0) p1 = i + 1;
            else if(curr == target) p2 = i + 1;
            else if(curr == target * 2) p3 = i + 1;
        }
        int pp2 = p2, pp3 = p3;
        while(p1 < pp2 && p2 < pp3 && p3 < n)
        {
            if((arr[p1] + arr[p2] + arr[p3]) % 3 != 0) return {-1, -1};
            p1++, p2++, p3++;
        }
        if(p3 == n) return {p1 - 1, p2};
        return {-1, -1};
    }
};