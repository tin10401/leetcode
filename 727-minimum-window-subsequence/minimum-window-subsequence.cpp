class Solution {
public:
    string minWindow(string s1, string s2) {
       int m = s1.size(), n = s2.size(), i = 0, j = 0, len = 1e8, start = -1;
       while(i < m)
       {
            if(s1[i] == s2[j])
            {
                if(++j == n)
                {
                   j--;
                   int end = i + 1;
                   while(j >= 0)
                   {
                        if(s1[i] == s2[j])
                        {
                            j--;
                        }
                        i--;
                   }     
                   j = 0;
                   i++;
                    if(end - i < len)
                    {
                        len = end - i;
                        start = i;
                    } 
                }
            }
            i++;
       } 
       return len == 1e8 ? "" : s1.substr(start, len);
    }
};