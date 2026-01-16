#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
#define pll pair<ll, ll>
#define endl "\n" 
#define all(v) v.begin(), v.end()
const int N = 2e5+123;
 
vector<ll> g[N]; 
vector<bool> vis;
vll par, lvl, ans;
 
void g_clear(int n){
    for(int i=0; i<=n; i++) g[i].clear();
    par.assign(n+1, -1);
    lvl.assign(n+1, 0);
    vis.assign(n+1, false);
}
 
void dfs(ll u) {
    vis[u] = true;
    for(auto v : g[u]) {
        if(!vis[v]) {
            dfs(v);
        }
    }
    ans.push_back(u);
}
 
void solve() {
 
    ll n, m; cin >> n >> m;
    g_clear(n);
    for(int i=1; i<=m; i++) {
        ll u, v; cin >> u >> v;
        g[u].push_back(v);
    }
 
    for(int i=1; i<=n; i++) if(!vis[i]) dfs(i);
 
    reverse(all(ans));
    vll mp(n+1, 0);
    for(int i=0; i<ans.size(); i++) mp[ans[i]] = i;
 
    bool ok = true;
    for(int i=1; i<=n; i++) {
        for(auto u : g[i]) {
            if(mp[i] >= mp[u]) {
                ok = false; 
            }
        }
    }
    
    if(!ok) cout << "IMPOSSIBLE" << endl;
    else {
        for(int i=0; i<n; i++) cout << ans[i] << " ";
    }
}
 
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    cout.tie(0);
 
    ll tc = 1; // cin >> tc;
    while(tc--) {
        solve();
    }
}
