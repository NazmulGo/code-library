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

ll gcd(ll a,ll b) { return __gcd(a,b); }
ll lcm(ll a,ll b) { return (a*b)/__gcd(a,b); }

int dx[] = {0, 0, 1, -1, 1, -1, -1, 1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

vector<pll> g[N]; // g[u] contains pair (v, weight)
vll dist(N); // dist[i] will store the shortest distance from source to node i

void dijkstra(ll src, ll n)
{
    for(int i=0; i<=n; i++) dist[i] = LLONG_MAX; 
    dist[src] = 0; // Distance to source is 0
    priority_queue<pll, vector<pll>, greater<pll>> pq; 
    pq.push({0, src});

    while(!pq.empty())
    {
        ll curDist = pq.top().first, u = pq.top().second; // Node with current shortest distance
        pq.pop();

        if(dist[u] < curDist) continue; // If already found a better path, skip

        // Explore all neighbors
        for(auto edge : g[u])
        {
            ll v = edge.first, weight = edge.second; // Neighbor node and edge weight
            if(weight + curDist < dist[v]) // If a better distance is found
            {
                dist[v] = weight + curDist; // Update distance
                pq.push({dist[v], v}); // Push the neighbor into queue
            }
        }
    }
}

void solve()
{
    ll n, m;
    cin >> n >> m;

    for(int i=1; i<=m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w; 
        g[u].pb({v, w}); 
        g[v].pb({u, w});
    }

    dijkstra(0, n); // Run Dijkstra from source node 0

    for(int i=0; i<n; i++) cout << dist[i] << " "; // Print shortest distances
    cout << endl;
}

int main()
{
    Baba_Yaga;
    ll tc = 1; 
    while(tc--) solve(); 
}
