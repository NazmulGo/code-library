#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
#define pll pair<ll, ll>
#define endl "\n" 
#define all(v) v.begin(), v.end()
#define fr(x, n) for (int i = x; i < n; ++i)
const int N = 101;

vll par(N), sz(N, 1);

int find_par(ll u) {
    if(par[u] == u) return u;
    return par[u] = find_par(par[u]);
}

void Union(int u, int v) {
    if(sz[u] < sz[v]) swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
}

void solve() {
    ll n, m; cin >> n >> m;   
    
    for(int i=1; i<=n; i++) par[i] = i;
    
    while(m--) {
        ll u, v; cin >> u >> v;

        int u_Rep = find_par( u );
        int v_Rep = find_par( v );

        if(u_Rep != v_Rep) {
            Union(u_Rep, v_Rep);
        }
    }
    for(int i=1; i<=n; i++) find_par(i); // force path compression

    
    for(int i=1; i<=n; i++) cout << i << " : " << par[i] << endl;
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
