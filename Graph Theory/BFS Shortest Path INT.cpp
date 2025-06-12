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
bool vis[N];
vector<ll> lvl(N), par(N, -1);

void bfs(int s) {
    queue<int> q;
    q.push(s);
    vis[s] = true;
    lvl[s] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (!vis[v]) {
                vis[v] = true;
                lvl[v] = lvl[u] + 1;
                par[v] = u;
                q.push(v);
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        ll u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);    
    }
    ll s, t; cin >> s >> t;
    bfs(s);

    if(lvl[t] == 0) return void(cout << "No route" << endl);

    vector<pair<ll,ll>> ans;
    while(par[t] != -1) {
        ans.push_back({par[t], t});
        t = par[t];
    }

    reverse(all(ans));
    for(auto u : ans) cout << u.first << " " << u.second << endl;

}

// --- Think the problem backwards ---

int main()
{
    ll tc = 1; //cin >> tc;
    while(tc--) solve();
}
