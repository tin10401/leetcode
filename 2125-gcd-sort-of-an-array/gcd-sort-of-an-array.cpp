class UnionFind
{
    public:
    vector<int> root, rank;
    int n;
    UnionFind(int n)
    {
        this->n = n;
        root.resize(n, -1);
        rank.resize(n, 1);
    }

    int find(int x)
    {
        if(root[x] == -1) return x;
        return root[x] = find(root[x]);
    }

    void merge(int x, int y)
    {
        int u = find(x), v = find(y);
        if(u != v)
        {
            if(rank[v] > rank[u]) swap(u, v);
            rank[u] += rank[v];
            root[v] = u;
        }
    }

    bool queries(vector<int>& nums)
    {
        vector<vector<int>> graph(n);
        vector<vector<int>> list(n);
        for(int i = 0; i < n; i++)
        {
            int x = find(i);
            graph[x].push_back(nums[i]);
            list[x].push_back(i);
        }
        for(int i = 0; i < n; i++)
        {
            auto& it = graph[i];
            sort(begin(it), end(it));
            for(int j = 0; j < it.size(); j++)
            {
                nums[list[i][j]] = it[j];
            }
        }
        for(int i = 1; i < n; i++)
        {
            if(nums[i] < nums[i - 1]) return false;
        }
        return true;
    }
};

class Solution {
public:
    bool gcdSort(vector<int>& nums) {
        int n = nums.size();
        UnionFind root(n);
        unordered_map<int, int> indices;
        for(int i = 0; i < n; i++)
        {
            int num = nums[i];
            for(int j = 2; j <= sqrt(num); j++)
            {
                if(num % j == 0)
                {
                    if(indices.count(j)) root.merge(indices[j], i);
                    indices[j] = i;
                    while(num % j == 0) num /= j;
                }
            }
            if(num > 1)
            {
                if(indices.count(num)) root.merge(indices[num], i);
                indices[num] = i;
            }
        }
        return root.queries(nums);
    }
};