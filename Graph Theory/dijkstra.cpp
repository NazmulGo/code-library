#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

#define pb push_back
#define MOD 1000000007
#define vll vector<ll>
#define pll pair<ll, ll>
#define endl "\n" 
#define all(v) v.begin(), v.end()
#define mem(a,b) memset(a, b, sizeof(a))
#define co(n) cout << n << endl
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define fr(x, n) for (int i = x; i < n; ++i)
#define fraction(x) cout << fixed << setprecision(x)
#define Baba_Yaga ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
 
const double eps = 1e-9;
const int N = 1e5+123;
const ll mx = 1e18;
ll gcd(ll a,ll b) { return __gcd(a,b); }
ll lcm(ll a,ll b) { return (a*b)/__gcd(a,b); }

int dx[] = {0, 0, 1, -1, 1, -1, -1, 1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

vector<pll> g[N];
vll dist(N);

void dijkstra(ll src, ll n)
{
    for(int i=0; i<=n; i++) dist[i] = mx;
    dist[src] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, src});

    while(!pq.empty())
    {
        ll curDist = pq.top().first;
        ll u = pq.top().second;
        pq.pop();
        
        if(curDist > dist[u]) continue;
        
        for(auto edge : g[u])
        {
            ll  weight = edge.second, v = edge.first;

            if(curDist + weight < dist[v])
            {
                dist[v] = curDist + weight;
                pq.push({dist[v], v});
            }

        }
    }
}

void solve()
{
    ll n, m; cin >> n >> m;
    map<pll, ll> mp;
    for(int i=1; i<=m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        if (mp.find({u, v}) == mp.end() || w < mp[{u, v}]) 
        {
            mp[{u, v}] = w;
        }
    }

    for(auto e : mp)
    {
        ll u = e.first.first;
        ll v = e.first.second;
        ll w = e.second;
        g[u].pb({v, w});

    }

    dijkstra(1, n);
    for(int i=1; i<=n; i++) cout << dist[i] << " "; cout << endl;
}

// --- Think the problem backwards ---

int main()
{
    Baba_Yaga;
    ll tc = 1; // cin >> tc;
    while(tc--) solve();
}
