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
vector<ll> lvl(N, -1); 

bool yo = true;

void bfs(int s) {
    queue<int> q;
    q.push(s);
    lvl[s] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (lvl[v] == -1) {
                lvl[v] = lvl[u]+1;
                q.push(v);
            }
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
    bfs(1);
    for(int i=1; i<=n; i++) {
        cout << lvl[i] << " ";
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
