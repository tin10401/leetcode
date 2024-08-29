class DSU { 
    public: 
    int n;  
    vector<int> root;
    DSU(int n) {    
        this->n = n;    
        root.resize(n, -1);
    }
    
    int find(int x) {   
        if(root[x] == -1) return x; 
        return root[x] = find(root[x]);
    }
    
    void merge(int x, int y) {  
        x = find(x), y = find(y);   
        if(x != y) root[x] = y, n--;
    }
    
    int next(int x) {return find(x);}
    
    int get() { return n; }
};
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        DSU root(n);
        vector<int> res;
        vector<bool> vis(n);
        for(auto& q : queries) {
            int start = q[0], end = q[1] - 1;
            while(start < end) {
                root.merge(start, start + 1);
                start = root.next(start);
            }
            res.push_back(root.get() - 1);
        }
        return res;
    }
};