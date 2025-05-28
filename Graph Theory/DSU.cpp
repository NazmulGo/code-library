#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
#define pll pair<ll, ll>
#define endl "\n" 
#define all(v) v.begin(), v.end()
#define fr(x, n) for (int i = x; i < n; ++i)
const int N = 1e5+123;

#define yes cout << "YES" << endl
#define no cout << "NO" << endl

vll par(N), sz(N);

ll find_par(ll u) {
    if(u == par[u]) return u;
    return par[u] = find_par(par[u]);
}

void Union(ll u, ll v) {
    if(sz[u] < sz[v]) swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
}

void solve() {
    ll n, q; cin >> n >> q;
    for(int i=1; i<=n; i++) par[i] = i, sz[i] = 1;
    while(q--) {
        string s; cin >> s;
        ll u, v; cin >> u >> v;
        
        ll uR = find_par( u );
        ll vR = find_par( v );
        
        if(s == "union") {
            if(uR != vR) {
                Union(uR, vR);
            }
        }
        else if(s == "get") {
            if(uR == vR) yes;
            else no;
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
