class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res = 0;
        for(string& detail : details)
        {
            int temp = stoi(detail.substr(11, 2));
            if(temp > 60)
            {
                res++;
            }
        }
        return res;
    }
};