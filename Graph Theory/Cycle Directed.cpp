// Created on: 2026-01-14 19:01
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
vll lvl, par;
int start = -1, finish = -1;
 
void g_clear(int n){
    for(int i=0; i<=n; i++) g[i].clear();
    lvl.assign(n+1, 0);
    par.assign(n+1, -1);
}
 
void dfs(ll u, ll p) {
    lvl[u] = 1;
    par[u] = p;
    for(auto v : g[u]) {
        if(lvl[v] == 0) {
            dfs(v, u);
        }
        else if(lvl[v] == 1) {
            start = u, finish = v;
        }
    }
    lvl[u] = 2;
}
 
void find_cycle(ll n) {
 
    for(int i=1; i<=n; i++) {
        if(lvl[i] == 0 && start == -1) dfs(i, 0);
    }
 
    if(start == -1) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        vll x; 
        ll node = start;
        while(node != finish) {
            x.push_back(node);
            node = par[node];
        }
        x.push_back(finish);
        x.push_back(start);
        reverse(all(x));
        
        cout << x.size() << endl;
        for(int i=0; i<x.size(); i++) cout << x[i] << " "; 
    }
}
 
void solve() {
 
    ll n, m; cin >> n >> m;
    g_clear(n);
 
    for(int i=1; i<=m; i++) {
        ll u, v; cin >> u >> v;
        g[u].push_back(v);
    }
 
    find_cycle(n);
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
11 13
1 2
2 3
4 3
1 7
7 6
5 6
4 5
10 4
9 10
8 9
5 11
8 11
4 8 
*/ 
 
/*
5
10 4 8 9 10 
*/
