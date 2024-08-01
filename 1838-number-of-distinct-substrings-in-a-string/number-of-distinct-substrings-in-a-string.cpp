const int MX = 501;
int gap, n, pos[MX], sa[MX], tmp[MX], lcp[MX];
string s;
bool comp(int x, int y)
{
    if(pos[x] != pos[y]) return pos[x] < pos[y];
    x += gap, y += gap;
    return x < n && y < n ? pos[x] < pos[y] : x > y;
}
void suffix()
{
    for(int i = 0; i < n; i++) sa[i] = i, pos[i] = s[i];
    for(gap = 1;; gap <<= 1)
    {
        sort(sa, sa + n, comp);
        for(int i = 0; i < n - 1; i++)
        {
            tmp[i + 1] = tmp[i] + comp(sa[i], sa[i + 1]);
        }
        for(int i = 0; i < n; i++) pos[sa[i]] = tmp[i];
        if(tmp[n - 1] == n - 1) break;
    }
}
void build_lcp()
{
    for(int i = 0, k = 0; i < n; i++)
    {
        if(pos[i] == n - 1) continue;
        int j = sa[pos[i] + 1];
        while(s[i + k] == s[j + k]) k++;
        lcp[pos[i]] = k;
        if(k) k--;
    }
}
class Solution {
public:
    int countDistinct(string str) {
        fill(tmp, tmp + n, 0), fill(lcp, lcp + n, 0);
        n = str.size();
        s = str;
        suffix(), build_lcp();
        return n * (n + 1) / 2 - accumulate(lcp, lcp + n, 0LL); 

    }
};