class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int res = 1;
        unordered_set<int> s;
        for(auto& num : rolls)
        {
            s.insert(num);
            if(s.size() == k) 
            {
                res++;
                s.clear();
            }
        }
        return res;
    }
};