class SegmentTree
{
    public:
    vector<pair<int, int>> root;
    int n;
    SegmentTree() {}

    void build(vector<int>& arr)
    {
        this->n = arr.size();
        root.resize(n * 4);
        build(0, 0, n - 1, arr);
    }

    void build(int i, int left, int right, vector<int>& arr)
    {
        if(left == right)
        {
            root[i] = {arr[left], 1};
            return;
        }
        int middle = left + (right - left) / 2;
        build(i * 2 + 1, left, middle, arr);
        build(i * 2 + 2, middle + 1, right, arr);
        root[i] = merge(root[i * 2 + 1], root[i * 2 + 2]);
    }

    pair<int, int> merge(pair<int, int> a, pair<int, int> b)
    {
        if(a.first == b.first) return {a.first, a.second + b.second};
        if(a.second > b.second) return {a.first, a.second - b.second};
        return {b.first, b.second - a.second};
    }

    int get(int start, int end)
    {
        return get(0, 0, n - 1, start, end).first;
    }

    pair<int, int> get(int i, int left, int right, int start, int end)
    {
        if(left >= start && right <= end) return root[i];
        if(left > end || right < start) return {0, 0};
        int middle = left + (right - left) / 2;
        return merge(get(i * 2 + 1, left, middle, start, end), get(i * 2 + 2, middle + 1, right, start, end));
    }

};

class MajorityChecker {
public:
    SegmentTree root;
    unordered_map<int, vector<int>> list;
    MajorityChecker(vector<int>& arr) {
        root.build(arr);
        for(int i = 0; i < arr.size(); i++)
        {
            list[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int threshold) {
        int e = root.get(left, right);
        int leftRange = lower_bound(list[e].begin(), list[e].end(), left) - begin(list[e]);
        int rightRange = upper_bound(list[e].begin(), list[e].end(), right) - begin(list[e]);
        if(rightRange - leftRange >= threshold) return e;
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */