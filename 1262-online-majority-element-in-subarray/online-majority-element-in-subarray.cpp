class Node {
public:
    int val;
    int freq;
    Node(int v = 0, int f = 0) : val(v), freq(f) {}
};

Node merge(Node a, Node b) {
    if (a.val == b.val) {
        return Node(a.val, a.freq + b.freq);
    }
    if (a.freq > b.freq) {
        return Node(a.val, a.freq - b.freq);
    }
    return Node(b.val, b.freq - a.freq);
}

class MajorityChecker {
public:
    int n;
    vector<int> arr;
    vector<Node> tree;
    unordered_map<int, vector<int>> indexes;

    MajorityChecker(vector<int>& arr) {
        this->n = arr.size();
        this->arr = arr;
        int size = 1 << (int)ceil(log2(this->n)) + 1;
        tree.resize(size);
        build(0, 0, this->n - 1);
    }

    void build(int pos, int l, int r) {
        if (l == r) {
            tree[pos] = Node(arr[l], 1);
            indexes[arr[l]].push_back(l);
        } else {
            int mid = (l + r) / 2;
            build(pos * 2 + 1, l, mid);
            build(pos * 2 + 2, mid + 1, r);
            tree[pos] = merge(tree[pos * 2 + 1], tree[pos * 2 + 2]);
        }
    }

    Node pquery(int pos, int start, int end, int l, int r) {
        if (l > end || r < start) {
            return Node(0, 0);
        }
        if (start <= l && r <= end) {
            return tree[pos];
        }
        int mid = (l + r) / 2;
        Node a = pquery(pos * 2 + 1, start, end, l, mid);
        Node b = pquery(pos * 2 + 2, start, end, mid + 1, r);
        return merge(a, b);
    }

    int query(int l, int r, int threshold) {
        int candidate = pquery(0, l, r, 0, n - 1).val;
        if (candidate == 0) return -1;
        auto& index_list = indexes[candidate];
        auto s = lower_bound(index_list.begin(), index_list.end(), l);
        auto e = upper_bound(index_list.begin(), index_list.end(), r);
        return (e - s >= threshold) ? candidate : -1;
    }
};