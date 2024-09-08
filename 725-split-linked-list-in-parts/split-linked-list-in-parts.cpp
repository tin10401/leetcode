/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 //████████╗██╗███╗░░██╗  ██╗░░░░░███████╗
//╚══██╔══╝██║████╗░██║  ██║░░░░░██╔════╝
//░░░██║░░░██║██╔██╗██║  ██║░░░░░█████╗░░
//░░░██║░░░██║██║╚████║  ██║░░░░░██╔══╝░░
//░░░██║░░░██║██║░╚███║  ███████╗███████╗
//░░░╚═╝░░░╚═╝╚═╝░░╚══╝  ╚══════╝╚══════╝
//   __________________
//  | ________________ |
//  ||          ____  ||
//  ||   /\    |      ||
//  ||  /__\   |      ||
//  || /    \  |____  ||
//  ||________________||
//  |__________________|
//  \###################\
//   \###################\
//    \        ____       \
//     \_______\___\_______\
// An AC a day keeps the doctor away.

#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("popcnt")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define vt vector
#define all(x) begin(x), end(x)
#define allr(x) rbegin(x), rend(x)
#define ub upper_bound
#define lb lower_bound
#define db double
#define ld long db
#define ll long long
#define pll pair<ll, ll>    
#define vll vt<ll>  
#define vpll vt<pll>
#define vi vector<int>
#define pii pair<int, int>
#define vpii vector<pair<int, int>>
#define vs vector<string>
#define vb vector<bool>
#define vvpii vector<vpii>
#define vvi vector<vi>
#define vd vector<db>
#define ar(x) array<int, x>
#define var(x) vector<ar(x)>
#define pq priority_queue
#define mset(m, v) memset(m, v, sizeof(m))
#define pb push_back
#define ff first
#define ss second
#define sv string_view
#define MP make_pair
#define MT make_tuple
#define rsz resize
#define sum(x) accumulate(all(x), 0LL)
#define srt(x) sort(all(x))
#define srtR(x) sort(allr(x))
#define srtU(x) sort(all(x)), (x).erase(unique(all(x)), (x).end())
#define rev(x) reverse(all(x))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define MAX(a) *max_element(all(a)) 
#define MIN(a) *min_element(all(a))

//SGT DEFINE
#define lc i * 2 + 1
#define rc i * 2 + 2
#define lp lc, left, middle
#define rp rc, middle + 1, right
#define entireTree 0, 0, n - 1
#define midPoint left + (right - left) / 2
#define pushDown push(i, left, right)
#define iterator int i, int left, int right

#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
    
//FW TREE   
#define goUp id += (id & -id)   
#define goDown id -= (id & -id)

struct custom {
    static const uint64_t C = 0x9e3779b97f4a7c15; const uint32_t RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
    size_t operator()(uint64_t x) const { return __builtin_bswap64((x ^ RANDOM) * C); }
    size_t operator()(const std::string& s) const { size_t hash = std::hash<std::string>{}(s); return hash ^ RANDOM; } };
template <class K, class V> using umap = std::unordered_map<K, V, custom>; template <class K> using uset = std::unordered_set<K, custom>;
    
 
template<typename T> vt<T> uniqued(vt<T> arr) {  srtU(arr); return arr; }

#ifdef LOCAL
#define debug(x...) debug_out(#x, x)
void debug_out(const char* names) { std::cerr << std::endl; }
template <typename T, typename... Args>
void debug_out(const char* names, T value, Args... args) {
    const char* comma = strchr(names, ',');
    std::cerr << "[" << (comma ? std::string(names, comma) : names) << " = " << value << "]";
    if (sizeof...(args)) { std::cerr << ", "; debug_out(comma + 1, args...); }   
    else { std::cerr << std::endl; }
}
#define startClock clock_t tStart = clock();
#define endClock std::cout << std::fixed << std::setprecision(10) << "\nTime Taken: " << (double)(clock() - tStart) / CLOCKS_PER_SEC << " seconds" << std::endl;
#else
#define debug(...)
#define startClock
#define endClock

#endif
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define eps 1e-9
#define M_PI 3.14159265358979323846
const static ll INF = 1LL << 60;
const static int MK = 20;
const static int MX = 2e6 + 5;
const static int MOD = 1e9 + 7;
const static string no = "NO\n";
const static string yes = "YES\n";
constexpr int pct(int x) { return __builtin_popcountll(x); }
const vvi dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // UP, DOWN, LEFT, RIGHT
constexpr int modExpo(int base, int exp, int mod) { int res = 1; base %= mod; while(exp) { if(exp & 1) res = (res * base) % mod; base = (base * base) % mod; exp >>= 1; } return res; }
void multiply(int f[2][2], int m[2][2]) {   
    int res[2][2] = {}; 
    for(int i = 0; i < 2; i++)  {   for(int j = 0; j < 2; j++)  {   for(int k = 0; k < 2; k++)  {   res[i][j] = (res[i][j] + f[i][k] * m[k][j]) % MOD; }   }   }   
    for(int i = 0; i < 2; i++)  {   for(int j = 0; j < 2; j++) f[i][j] = res[i][j]; }   }
int fib(int n)  {       if(n == 0) return 0;        if(n == 1) return 1;    
    int f[2][2] = {{1, 1}, {1, 0}}; int res[2][2] = {{1, 0}, {0, 1}};       
    while(n)    {   if(n & 1) multiply(res, f); multiply(f, f); n >>= 1;    }   return res[0][1] % MOD; }   
vi primes;  
bitset<MX> primeBits;
void generatePrime() {  primeBits.set(2);   
    for(int i = 3; i < MX; i += 2) primeBits.set(i);
    for(int i = 3; i * i < MX; i += 2) {    if(primeBits[i]) {  for(int j = i; j * i < MX; j += 2) {    primeBits.reset(i * j); } } }
    for(int i = 0; i < MX; i++ ) {  if(primeBits[i]) {  primes.pb(i); } }   
}
    
class DSU { 
    public: 
    int n;  
    vi root, rank;  
    DSU(int n) {    
        this->n = n;    
        root.rsz(n, -1), rank.rsz(n, 1);
    }
    
    int find(int x) {   
        if(root[x] == -1) return x; 
        return root[x] = find(root[x]);
    }
    
    void merge(int u, int v) {  
        u = find(u), v = find(v);   
        if(u != v) {    
            if(rank[v] > rank[u]) swap(u, v);   
            rank[u] += rank[v]; 
            root[v] = u;
        }
    }
    
    bool isConnected(int u, int v) {    
        return find(u) == find(v);
    }
};
    
class FW {  
    public: 
    int n;  
    vi root;    
    FW(int n) { 
        this->n = n;    
        root.rsz(n + 1);
    }
    
    void update(int id, int val) {  
        while(id <= n) {    
            root[id] += val;    
            goUp;
        }
    }
    
    int get(int id) {   
        int res = 0;    
        while(id > 0) { 
            res += root[id];    
            goDown;
        }
        return res;
    }
    
    int queries(int left, int right) {  
        return get(right) - get(left - 1);
    }
};

template<class T>   
class SGT { 
    public: 
    int n;  
    vt<T> root, lazy; 
    SGT(vi& arr) {    
        n = arr.size(); 
        root.rsz(n * 4);    
        // lazy.rsz(n * 4);
        build(entireTree, arr);
    }
    
    void build(iterator, vi& arr) { 
        if(left == right) { 
            root[i] = arr[left];    
            return;
        }
        int middle = midPoint;  
        build(lp, arr), build(rp, arr); 
        root[i] = merge(root[lc], root[rc]);
    }
    
    void update(int id, int val) {  
        update(entireTree, id, val);
    }
    
    void update(iterator, int id, int val) {    
        if(left == right) { 
            root[i] = val;  
            return;
        }
        int middle = midPoint;  
        if(id <= middle) update(lp, id, val);   
        else update(rp, id, val);   
        root[i] = merge(root[lc], root[rc]);
    }

    void update(int start, int end, int val) { 
        update(entireTree, start, end, val);
    }
    
    void update(iterator, int start, int end, int val) {    
        pushDown;   
        if(left > end || start > right) return; 
        if(left >= start && right <= end) { 
            lazy[i] = val;  
            pushDown;   
            return;
        }
        int middle = midPoint;  
        update(lp, start, end, val);    
        update(rp, start, end, val);    
        root[i] = merge(root[lc], root[rc]);
    }
    
    T merge(T left, T right) {  
        T res;  
        return res;
    }
    
    void push(iterator) {   
        if(lazy[i] == 0) return;    
        if(left != right) { 
            lazy[lc] = lazy[i]; 
            lazy[rc] = lazy[i];
        }
        lazy[i] = 0;
    }

    T queries(int start, int end) { 
        return queries(entireTree, start, end);
    }
    
    T queries(iterator, int start, int end) {   
        pushDown;
        if(left > end || start > right) return 0;   
        if(left >= start && right <= end) return root[i];   
        int middle = midPoint;  
        return merge(queries(lp, start, end), queries(rp, start, end));
    }

};
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length = 0;
        ListNode* curr = head;
        while(curr)
        {
            length++;
            curr = curr->next;
        }
        int extra = length % k, subLen = length / k;
        curr = head;
        vector<ListNode*> res;
        for(int i = 0; i < k; i++)
        {
            res.push_back(curr);
            for(int j = i; curr && j < i + subLen - 1 + (extra > 0); j++, curr = curr->next) {}
            extra--;
            if(curr)
            {
                ListNode* temp = curr->next;
                curr->next = nullptr;
                curr = temp;
            }
        }
        return res;
    }
};