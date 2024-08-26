class Solution {
    unordered_map<int, int> cnt;
    void add(unordered_set<int> &st, vector<int> &cur, vector<int> &f, int v, int c){
        st.insert(v);
        if(c == 2)  return;
        int m = cur.size();
        for(int i=0; i<m; ++i){
            for(int j=i+1; j<m; ++j){
                int w = v + cur[i] * (f[j] - f[i]) + cur[j] * (f[i] - f[j]);
                swap(cur[i], cur[j]);
                add(st, cur, f, w, c + 1);
                swap(cur[i], cur[j]);
            }
        }
    }
    void add(int y){
        int v = y;
        vector<int> cur;
        vector<int> f;
        int p = 1;
        while(y){
            cur.push_back(y % 10);
            y /= 10;
            f.push_back(p);
            p = p * 10;
        }
        reverse(cur.begin(), cur.end());
        reverse(f.begin(), f.end());
        unordered_set<int> st;
        add(st, cur, f, v, 0);
        for(int v : st){
            ++cnt[v];
        }
    }
public:
    int countPairs(vector<int>& a) {
        int ret = 0;
        sort(a.rbegin(), a.rend());
        for(int v : a){
            ret += cnt[v];
            add(v);
        }
        return ret;
    }
};