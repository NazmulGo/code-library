#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
#define pll pair<ll, ll>
#define endl "\n" 
#define all(v) v.begin(), v.end()
const int N = 5e3+12;

struct store {
    ll u, v, w;
};

vector<pll> g[N];
ll dist[2][N];

void dijkstra(ll src, ll n, ll which) {
    for(int i=0; i<=n; i++) dist[which][i] = LLONG_MAX;
    dist[which][src] = 0;

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, src});

    while(!pq.empty()) {
        ll u = pq.top().second, curD = pq.top().first;
        pq.pop();

        if(curD > dist[which][u]) continue;
        
        for(auto edge : g[u]) {
            ll v = edge.first, weight = edge.second;
            
            if(weight + curD < dist[which][v]) {
                dist[which][v] = weight + curD;
                pq.push({dist[which][v] , v});
            }
        }
    }
}

void solve() {

    for(int i=0; i<=(ll)5e3; i++) g[i].clear();
    vector<store> edges;
    ll n, m; cin >> n >> m;

    for(int i=1; i<=m; i++) {
        ll u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        edges.push_back({u, v, w});
    }

    dijkstra(1, n, 0);
    dijkstra(n, n, 1);

    ll min_cost = dist[0][n];
    ll best = LLONG_MAX;

    for(int i=0; i<edges.size(); i++) {
        ll cost = min( dist[0][edges[i].u] + dist[1][edges[i].v], dist[1][edges[i].u] + dist[0][edges[i].v]);
        cost += edges[i].w;
        if(cost > min_cost) best = min(best, cost);
        if(cost == min_cost) {
            cost += (edges[i].w * 2);
            best = min(best, cost);
        }
    }
    cout << best << endl;

}

// --- Think the problem backwards ---

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); 
    cout.tie(NULL);

    ll tc = 1; cin >> tc;
    for(int i=1; i<=tc; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
}
