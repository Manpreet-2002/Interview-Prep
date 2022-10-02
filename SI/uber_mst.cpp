#include <bits/stdc++.h>
// #include <sys/resource.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;

// Pragmas
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

// Aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;

// template<typename T>
// using oset =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Constants
constexpr int INF = 2e9;
constexpr ld EPS = 1e-9;
constexpr ll MOD = 1e9 + 7;

// Macros
#define F first
#define S second
#define all(x) begin(x), end(x)
#define allr(x) rbegin(x), rend(x)
#define int long long
#define endl '\n'

// Custom hash map
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
template <typename T1, typename T2> // Key should be integer type
using safe_map = unordered_map<T1, T2, custom_hash>;

// Operator overloads
template <typename T1, typename T2> // cin >> pair<T1, T2>
istream &operator>>(istream &istream, pair<T1, T2> &p)
{
    return (istream >> p.first >> p.second);
}

template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}

template <typename T1, typename T2> // cout << pair<T1, T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p)
{
    return (ostream << p.first << " " << p.second);
}
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}

// Utility functions
template <typename T>
void print(T &&t) { cout << t << "\n"; }
template <typename T, typename... Args>
void print(T &&t, Args &&...args)
{
    cout << t << " ";
    print(forward<Args>(args)...);
}

template <typename T>
int32_t size_i(T &container) { return static_cast<int32_t>(container.size()); }

// Mathematical functions
int GCD(int a, int b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

int GCD_extended(int a, int b, int &x, int &y)
{
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1)
    {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}
int LCM(int a, int b)
{
    return ((ll)a * b) / GCD(a, b);
}

ll modpow(ll x, ll n, int m = MOD)
{
    if (x == 0 && n == 0)
        return 0; // undefined case
    ll res = 1;
    while (n > 0)
    {
        if (n % 2)
            res = (res * x) % m;
        x = (x * x) % m;
        n /= 2;
    }
    return res;
}

int modinv(int x, int m = MOD)
{
    return modpow(x, m - 2, m);
}

mt19937 rng;
int getRandomNumber(int l, int r)
{
    uniform_int_distribution<int> dist(l, r);
    return dist(rng);
}

// void allocateStackMax()
// {
//     rlimit R;
//     getrlimit(RLIMIT_STACK, &R);
//     R.rlim_cur = R.rlim_max;
//     setrlimit(RLIMIT_STACK, &R);
// }

// Flags to use: -std=c++17 -O2 -DLOCAL_PROJECT -Wshadow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined
///////////////////////////////////////////////////////////// START CODE HERE /////////////////////////////////////////////////////////////

constexpr int N = 1e3;
vector<int> w(N + 1, 1e9);
void preSolve()
{
    rng = mt19937(chrono::steady_clock::now().time_since_epoch().count());
    // allocateStackMax();
}

int doFind(int n, vector<int> &parents)
{
    int par = parents[n];
    while (par != parents[par])
    {
        parents[par] = parents[parents[par]];
        par = parents[par];
    }
    return par;
}

bool doUnion(vector<int> &parents, vector<int> &ranks, int n1, int n2)
{
    int par1 = doFind(n1, parents);
    int par2 = doFind(n2, parents);
    if (par1 == par2)
    {
        return false;
    }
    if (ranks[par1] > ranks[par2])
    {
        parents[par2] = par1;
        ranks[par1] += ranks[par2];
    }
    else
    {
        parents[par1] = par2;
        ranks[par2] += ranks[par1];
    }
    return true;
}
int kruskals(int n, vector<vector<int>> &edges)
{
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq(edges.begin(), edges.end());
    vector<int> parents;
    vector<int> ranks;
    for (int i = 0; i < n + 1; i++)
    {
        parents.push_back(i);
        ranks.push_back(1);
    }
    int cost = 0;
    while (!pq.empty())
    {
        vector<int> temp = pq.top();
        pq.pop();
        int w = temp[0];
        int n1 = temp[1];
        int n2 = temp[2];
        if (doUnion(parents, ranks, n1, n2))
        {
            cost += w;
        }
    }
    return cost;
}
void solve(int tc)
{
    int n;
    cin >> n;
    vector<vector<int>> arr;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp(3);
        cin >> temp;
        arr.push_back(temp);
    }
    vector<vector<int>> edges;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int x1 = arr[i][0];
            int y1 = arr[i][1];
            int z1 = arr[i][2];
            int x2 = arr[j][0];
            int y2 = arr[j][1];
            int z2 = arr[j][2];
            int w = min({abs(x2 - x1), abs(y2 - y1), abs(z2 - z1)});
            edges.push_back({w, i, j});
        }
    }
    cout << kruskals(n, edges) << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(12) << fixed;

    preSolve();
    int tests = 1;
    // cin >> tests;
    for (int tt = 1; tt <= tests; tt++)
    {
        // cout << "Case #" << tt << ": ";
        solve(tt);
    }
    return 0;
}
