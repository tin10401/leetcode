class UnionFind {
public:
    vector<int> root, rank;
    vector<double> ratio;
    int n;

    UnionFind(int n) {
        this->n = n;
        root.resize(n);
        rank.resize(n, 1);
        ratio.resize(n, 1.0);
        for (int i = 0; i < n; ++i) {
            root[i] = i;
        }
    }

    int find(int x) {
        if (root[x] != x) {
            int oldRoot = root[x];
            root[x] = find(root[x]);
            ratio[x] *= ratio[oldRoot];
        }
        return root[x];
    }

    bool merge(int x, int y, double value) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
                ratio[rootY] = ratio[x] / (value * ratio[y]);
            } else {
                root[rootX] = rootY;
                ratio[rootX] = value * ratio[y] / ratio[x];
                if (rank[rootX] == rank[rootY]) {
                    rank[rootY]++;
                }
            }
        } else {
            double expected = ratio[x] / ratio[y];
            if (abs(value - expected) > 1e-6) {
                return true; // contradiction found
            }
        }
        return false;
    }
};

class Solution {
public:
    bool checkContradictions(vector<vector<string>>& equations, vector<double>& values) {
        unordered_map<string, int> indexMap;
        int n = 0;

        // Create index mapping for variables
        for (const auto& e : equations) {
            if (indexMap.find(e[0]) == indexMap.end()) indexMap[e[0]] = n++;
            if (indexMap.find(e[1]) == indexMap.end()) indexMap[e[1]] = n++;
        }

        UnionFind uf(n);

        // Process each equation
        for (int i = 0; i < equations.size(); ++i) {
            int u = indexMap[equations[i][0]];
            int v = indexMap[equations[i][1]];
            double value = values[i];

            if (uf.merge(u, v, value)) {
                return true; // contradiction found
            }
        }

        return false; // no contradiction found
    }
};