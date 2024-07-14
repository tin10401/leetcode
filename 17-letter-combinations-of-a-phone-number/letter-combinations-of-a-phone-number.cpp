class Solution {
public:
    // solution by tinle
    vector<string> res;
    void helper(int start, const string& digits, string str, unordered_map<char, string>& digitMap)
    {
        if(start == digits.size())
        {
            res.push_back(str);
            return;
        }
        for(const char& ch : digitMap[digits[start]])
        {
            helper(start + 1, digits, str + ch, digitMap);
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> digitMap;
        digitMap['2'] = "abc";
        digitMap['3'] = "def";
        digitMap['4'] = "ghi";
        digitMap['5'] = "jkl";
        digitMap['6'] = "mno";
        digitMap['7'] = "pqrs";
        digitMap['8'] = "tuv";
        digitMap['9'] = "wxyz";
        if(!digits.empty())
        {
            helper(0, digits, "", digitMap);
        }
        return res;
    }
};