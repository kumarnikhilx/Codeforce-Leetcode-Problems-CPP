#include <bits/stdc++.h>
using namespace std;

// -------------------- FAST IO --------------------
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

// -------------------- TYPEDEFS --------------------
using ll = long long;
using ull = unsigned long long;
using ld = long double;

// -------------------- MACROS --------------------
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())

// -------------------- CONSTANTS --------------------
const ll INF = 1e18;
const int MOD = 1e9 + 7;

// -------------------- DEBUG --------------------
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(int x) { cerr << x; }
void _print(ll x) { cerr << x; }
void _print(string x) { cerr << x; }
void _print(char x) { cerr << x; }
void _print(ld x) { cerr << x; }

template<class T, class V> void _print(pair<T,V> p);
template<class T> void _print(vector<T> v);
template<class T> void _print(set<T> v);
template<class T, class V> void _print(map<T,V> v);

template<class T, class V>
void _print(pair<T,V> p) {
    cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";
}

template<class T>
void _print(vector<T> v) {
    cerr << "[ ";
    for (auto i : v) { _print(i); cerr << " "; }
    cerr << "]";
}

template<class T>
void _print(set<T> v) {
    cerr << "[ ";
    for (auto i : v) { _print(i); cerr << " "; }
    cerr << "]";
}

template<class T, class V>
void _print(map<T,V> v) {
    cerr << "[ ";
    for (auto i : v) { _print(i); cerr << " "; }
    cerr << "]";
}

// -------------------- MATH UTILS --------------------
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

ll modExp(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

// -------------------- VECTOR IO --------------------
template<typename T>
void read(vector<T> &v) {
    for (auto &x : v) cin >> x;
}

template<typename T>
void print(vector<T> &v) {
    for (auto &x : v) cout << x << " ";
    cout << "\n";
}

// -------------------- SOLVE FUNCTION --------------------
void solve() {
    long long n,k;
    cin>>n>>k;


    if (n % 2 == 0 || (n - k) % 2 == 0) 
            cout << "YES" << endl; 
        else
            cout << "NO" << endl; 

    
    return ;

    
}   


// -------------------- MAIN --------------------
struct Edge {
    int to, w, id;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> adj(n + 1);

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w, i});
        adj[v].push_back({u, w, i});
    }

    int s;
    cin >> s;

    const ll INF = 4e18;

    vector<ll> dist(n + 1, INF);
    vector<int> parentEdge(n + 1, -1);
    vector<int> edgeWeight(n + 1, INT_MAX);

    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dist[u]) continue;

        for (auto &e : adj[u]) {

            ll newDist = d + e.w;

            if (newDist < dist[e.to]) {
                dist[e.to] = newDist;
                parentEdge[e.to] = e.id;
                edgeWeight[e.to] = e.w;
                pq.push({newDist, e.to});
            }
            else if (newDist == dist[e.to] && e.w < edgeWeight[e.to]) {
                parentEdge[e.to] = e.id;
                edgeWeight[e.to] = e.w;
            }
        }
    }

    ll total = 0;

    for (int i = 1; i <= n; i++) {
        if (i == s) continue;
        total += edgeWeight[i];
    }

    cout << total << "\n";

    for (int i = 1; i <= n; i++) {
        if (i == s) continue;
        cout << parentEdge[i] << " ";
    }

    return 0;
}