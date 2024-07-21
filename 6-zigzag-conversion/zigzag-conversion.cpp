class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
        {
            return s;
        }
        string list[numRows];
        int size = s.size();
        int index = 0;
        bool downward = true;
        for(int i = 0; i < size; i++)
        {
            if(index < 0)
            {
                downward = true;
                index = 1;
            }
            else if(index == numRows)
            {
                index = numRows - 2;
                downward = false;
            }
            if(downward)
            {
                list[index] += s[i];
                index++;
            }
            else
            {
                list[index] += s[i];
                index--;
            }
        }
        string temp;
        for(int i = 0; i < numRows; i++)
        {
            temp += list[i];
        }
        return temp;
    }
};