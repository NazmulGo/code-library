//https://cses.fi/problemset/task/1671/
 #include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
#define pll pair<ll, ll>
#define endl "\n" 
#define all(v) v.begin(), v.end()
const int N = 1e5+123;

ll n, m;
vector<pll> g[N];
vll cost(N);

void dijkstra(ll src, ll w) {
    for(int i=1; i<=n; i++) cost[i] = 1e18;
    cost[src] = 0;
   
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, src});
   
    while(!pq.empty()) {
        auto[curCost, u] = pq.top();
        pq.pop();

        if(curCost > cost[u]) continue;

        for(auto [v, weight] : g[u]) {
            if(weight + curCost < cost[v]) {
                cost[v] = weight + curCost;
                pq.push({cost[v], v});
            }
        }
    }
}


void solve() {
     cin >> n >> m;
    for(int i=0; i<m; i++) {
        ll u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    dijkstra(1, 0);
    for(int i=1; i<=n; i++) cout << cost[i] << " ";
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
