//https://cses.fi/problemset/task/1668/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
#define pll pair<ll, ll>
#define endl "\n" 
#define all(v) v.begin(), v.end()
#define fr(x, n) for (int i = x; i < n; ++i)
const int N = 2e5+123;

ll n, m;
vector<ll> g[N];
vll ans(N);
bool vis[N];
bool yo = true;

void dfs(ll u, ll color) {
    vis[u] = true;
    ans[u] = color;
    for(auto v : g[u]) {
        if(!vis[v]) {
            dfs(v, color == 1 ? 2:1);
        }
        else if(ans[v] == ans[u]) yo = false; // IMPOSSIBLE
    }
}

void solve() {
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        ll u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            dfs(i, 1);
        }
    }
    if(!yo) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        for(int i=1; i<=n; i++) {
            cout << ans[i] << " ";
        }
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
