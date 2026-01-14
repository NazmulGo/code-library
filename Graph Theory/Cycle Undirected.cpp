// Created on: 2026-01-14 16:48
// By the hand of: Nazmul_Huda
 
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
vll par, lvl;
int starting = -1, ending = -1;
 
void g_clear(int n){
    for(int i=0; i<=n; i++) g[i].clear();
    par.assign(n+1, -1);
    lvl.assign(n+1, -1);
    vis.assign(n+1, false);
}
 
void dfs(ll u, ll p) {
    vis[u] = true;
    par[u] = p;
    for(auto v : g[u]) {
        if(!vis[v]) {
            dfs(v, u);
        }
        else if(vis[v] && v != p) {
            starting = u, ending = v;
        }
    }
}
 
void cycle(ll n) {
    for(int i=1; i<=n; i++) {
        if(!vis[i] && starting == -1) dfs(i, 0);
    }

    if(starting == -1) cout << "IMPOSSIBLE" << endl;
    else {
        vll x;
        ll node = ending;
        // cout << starting << " " << ending << endl;
        // traverse from ending to starting
        while(node != starting) {
            x.push_back(node);
            node = par[node];
        }
        x.push_back(starting);
        x.push_back(ending);
        cout << x.size() << endl;
        for (int i = 0; i < x.size(); i++) {
            cout << x[i] << " ";
        }
    }
}
 
void solve() {
    ll n, m; cin >> n >> m;
    g_clear(n);
 
    for(int i=1; i<=m; i++) {
        ll u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    cycle(n);
}
 
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    cout.tie(0);
 
    ll tc = 1; // cin >> tc;
    while(tc--) {
        solve();
    }
}
