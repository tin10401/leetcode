/**
 * Definition for an infinite stream.
 * class InfiniteStream {
 * public:
 *     InfiniteStream(vector<int> bits);
 *     int next();
 * };
 */
class Solution {
public:
    int findPattern(InfiniteStream* stream, vector<int>& pattern) {
        int n = pattern.size();
        vector<int> prefix(n);
        for(int i = 1, j = 0; i < n; i++)
        {
            while(j && pattern[i] != pattern[j]) j = prefix[j - 1];
            if(pattern[i] == pattern[j]) prefix[i] = ++j;
        }
        for(int i = 0, j = 0, curr = stream->next(); j < n;)
        {
            if(curr == pattern[j]) j++, curr = stream->next(), i++;
            else if(j == 0) curr = stream->next(), i++;
            else j = prefix[j - 1];
            if(j == n) return i - n;
        }
        return -1;
    }
};