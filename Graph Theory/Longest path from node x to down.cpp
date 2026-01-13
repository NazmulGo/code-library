// Created on: 2026-01-14 00:21
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

void g_clear(int n){
    for(int i=0; i<=n; i++) g[i].clear();
    par.assign(n+1, 0);
    lvl.assign(n+1, 1);
    vis.assign(n+1, false);
}

ll dfs(ll u) {
    vis[u] = true;
    for(auto v : g[u]) {

        if(!vis[v]) {
            lvl[u] = max(lvl[u], dfs(v) + 1);
        }
    }
    return lvl[u];
}

void solve() {
    ll n; cin >> n;
    g_clear(n);
    for(int i=1; i<n; i++) {
        ll u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);
    for(int i=1; i<=n; i++) cout << lvl[i] << " ";
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    cout.tie(0);

    ll tc = 1; // cin >> tc;
    while(tc--) {
        solve();
    }
}

/* 
11
1 2
2 3
3 5
2 4
4 10
1 6
6 7
6 8 
8 9
5 11
*/
