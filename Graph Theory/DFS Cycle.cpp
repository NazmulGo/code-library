// "If from a node, I can go to an already visited node that is not its parent, then a cycle exists."
//https://cses.fi/problemset/task/1669/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
#define pll pair<ll, ll>
#define endl "\n" 
#define all(v) v.begin(), v.end()
#define fr(x, n) for (int i = x; i < n; ++i)
const int N = 2e5+123;

ll n, m, st = -1, ed = -1;
bool vis[N];
vector<ll> g[N], parent(N);
bool cycleFound = false;

void dfs(ll u, ll par) {
    vis[u] = true;
    parent[u] = par;
    for(auto v : g[u]) {
        if(!vis[v]) {
            dfs(v, u);
        }
        else if(vis[v] && v != par) {
            cycleFound = true;
            st = u, ed = v;
        }
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
            dfs(i, -1);
            if(cycleFound) break;
        }
    }

    if(!cycleFound) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    vll ans;
    ans.push_back(st);
    while(ed != st) {
        ans.push_back(ed);
        ed = parent[ed];
    }
    ans.push_back(st);

    cout << ans.size() << endl;
    for(auto x : ans) cout << x << " ";

}

// --- Try to formulate equations. ---

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    cout.tie(0);

    ll tc = 1; //cin >> tc;
    while(tc--) {
        solve();
    }
}
