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
    int n;

long long getMaxHappiness(int row, int prev, vector <vector <long long>> &dp, vector <vector <int>> &grid)
{
    if (row == (int) 0){
        long long lastRowMaxi=0;

        for(int i=0;i<3;i++){
           if(i!=prev) lastRowMaxi=max(lastRowMaxi,grid[row][i]*1LL);

        }
        return lastRowMaxi;

    } 

    if (dp[row][prev+1] != -1)
    {
        return dp[row][prev+1];
    }

    long long maxVal = 0;

    for (int col = 0; col < 3; col ++)
    {
        if (col != prev)
        {
            maxVal = max(maxVal, grid[row][col] + getMaxHappiness(row-1, col, dp, grid));
        }
    }

    return (dp[row][prev+1] = maxVal);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

  

   // while(t--){

    cin >>n;

    vector <vector <int>> grid(n, vector <int> (3, 0));

    // vector <vector <long long>> dp(n, vector <long long> (4, -1)); //used in memoization.
    vector<vector<long long>> dp(n, vector<long long>(3));


    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < 3; j ++)
        {
           cin >> grid[i][j];
        }
    }    

    //tabulation 
 
    // Base Case
    dp[0][0] = grid[0][0];
    dp[0][1] = grid[0][1];
    dp[0][2] = grid[0][2];

    // Transition
    //one in this way as well we can do it.
    // for(int i = 1; i < n; i++){
       

    //     dp[i][0] = grid[i][0] + max(dp[i-1][1], dp[i-1][2]);

    //     dp[i][1] = grid[i][1] + max(dp[i-1][0], dp[i-1][2]);

    //     dp[i][2] = grid[i][2] + max(dp[i-1][0], dp[i-1][1]);
    // }
    // this is the another way to do it.

    for(int day = 1; day < n; day++){

    for(int curr = 0; curr < 3; curr++){

        dp[day][curr] = 0;

        for(int prev = 0; prev < 3; prev++){

            if(curr != prev){

                dp[day][curr] = max(dp[day][curr],
                                    grid[day][curr] + dp[day-1][prev]);
            }
        }
    }
}
     cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});

   


    // cout << getMaxHappiness(n-1, -1, dp, grid); //recursion 

    cout<<"\n";

    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}