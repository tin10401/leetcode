#include <vector>
#include <algorithm>
#include <numeric>

class DistanceLimitedPathsExist {
public:
    const int N = 10010;
    std::vector<int> par, rank, weight;
    const int imax = INT_MAX;

    DistanceLimitedPathsExist(int n, std::vector<std::vector<int>>& edgeList) {
        par.resize(N);
        rank.resize(N, 1);
        weight.resize(N, 0);
        std::iota(par.begin(), par.end(), 0);  // Initialize parent array with its indices

        std::sort(edgeList.begin(), edgeList.end(), [](const std::vector<int>& e1, const std::vector<int>& e2) {
            return e1[2] < e2[2];
        });

        for(const auto& edge : edgeList) {
            unionSets(edge[0], edge[1], edge[2]);
        }
    }

    bool query(int p, int q, int limit) {
        return find(p, limit) == find(q, limit);
    }

private:
    int find(int i, int limit) {
        if(par[i] == i || weight[i] >= limit) return i;
        return find(par[i], limit);
    }

    void unionSets(int i, int j, int limit) {
        int ri = find(i, imax);
        int rj = find(j, imax);
        if(ri != rj) {
            if(rank[ri] <= rank[rj]) {
                par[ri] = rj;
                rank[rj] += rank[ri];
                weight[ri] = limit;
            } else {
                par[rj] = ri;
                rank[ri] += rank[rj];
                weight[rj] = limit;
            }
        }
    }
};
