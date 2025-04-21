#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

#define pb push_back
#define all(v) v.begin(), v.end()
#define fr(x, n) for (int i = x; i < n; ++i)
#define Baba_Yaga ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
const int N = 1e5 + 12;

vll g[N];
bool vis[N];
ll par[N];
ll n, m;
ll st = -1, ed = -1;

bool foundCycle = false;
void dfs(ll u, ll parent)
{
    vis[u] = true;
    par[u] = parent;
    for (ll v : g[u]) 
    {
        if (!vis[v]) 
        {
            dfs(v, u);
        } 
        else if (v != parent && !foundCycle) 
        {
            st = v;
            ed = u;
            foundCycle = true;
        }
    }
}

void solve() 
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) 
    {
        ll u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    for (int i = 1; i <= n; ++i) 
    {
        if (!vis[i]) 
        {
            dfs(i, -1);
        }
    }

    if (!foundCycle) 
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    vll cycle;
    cycle.pb(st);
    ll cur = ed;
    while (cur != st) 
    {
        cycle.pb(cur);
        cur = par[cur];
    }
    cycle.pb(st);

    cout << cycle.size() << endl;
    for(int i=0; i<cycle.size(); i++) cout << cycle[i] << " ";
}

int main() {
    Baba_Yaga;
    ll tc = 1; //  cin >> tc;
    while (tc--) 
    {
        solve();
    }
}
