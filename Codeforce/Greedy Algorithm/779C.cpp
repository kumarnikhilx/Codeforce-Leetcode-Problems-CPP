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
int main() {
    fastio();

#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
  
 int n,k;
    cin>>n>>k;

   
    vector<int> today(n);
    vector<int>later(n);
    for(int i=0;i<n;i++){
        cin>>today[i];
    }

    for(int i=0;i<n;i++){
        cin>>later[i];
    }

       vector<pair<int, pair<int, int>>> products;

   for (int i = 0; i < n; i++) {
        int extra = today[i] - later[i];
        products.push_back({extra, {today[i], later[i]}});
    }

    sort(products.begin(), products.end());
    int total=0;
  for (auto &p : products) {
        int extra = p.first;
        int t = p.second.first;
        int l = p.second.second;

        if (extra <= 0) {
            total += t;
            k--;
        }
        else if (k > 0) {
            total += t;
            k--;
        }
        else {
            total += l;
        }
    }
    cout<<total<<"\n";





 return 0;


    


}