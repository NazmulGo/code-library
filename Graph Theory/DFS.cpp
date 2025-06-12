https://cses.fi/problemset/task/1666/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
#define pll pair<ll, ll>
#define endl "\n" 
#define all(v) v.begin(), v.end()
#define fr(x, n) for (int i = x; i < n; ++i)
const int N = 2e5+123;

bool vis[N];
vector<ll> g[N];

void dfs(ll u) {
    vis[u] = true;
    for(auto v : g[u]) {
        if(!vis[v]) {
            dfs(v);
        }
    }
}

void solve() {
    ll n, m; cin >> n >> m;
    for(int i=1; i<=m; i++) {
        ll u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vll str;
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            dfs(i);
            str.push_back(i);
        }
    }
    cout << str.size() - 1 << endl;
    for(int i=1; i<str.size(); i++) {
        cout << str[i-1] << " " << str[i] << endl;
    }
}

// --- Try to formulate equations. ---

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    cout.tie(0);

    ll tc = 1; // cin >> tc;
    while(tc--) {
        solve();
    }
}
