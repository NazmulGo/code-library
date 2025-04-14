#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

#define pb push_back
#define MOD 1000000007
#define vll vector<ll>
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
const int N = 123;

ll gcd(ll a,ll b) { return __gcd(a,b); }
ll lcm(ll a,ll b) { return (a*b)/__gcd(a,b); }

vll adj[N];
ll lvl[N];
ll parent[N];

void bfs(ll s)
{
   lvl[s] = 1;
   queue<ll> q;
   q.push(s);
   while(!q.empty())
   {
      ll val = q.front();
      q.pop();

      for(auto u : adj[val])
      {
        if(lvl[u] == 0)
        {
            lvl[u] = lvl[val]+1;
            q.push(u);
            parent[u] = val;
        }
      }
   }
}

void solve()
{
    mem(parent, -1);
    ll n; cin >> n;
    for(int i=0; i<n; i++)
    {
        ll a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    ll s, t; cin >> s >> t;
    bfs(s);

    if(lvl[t] == 0) return void(cout << "No route" << endl);

    vector<pair<ll,ll>> ans;

    while(parent[t] != -1)
    {
        ans.push_back({parent[t], t});
        t = parent[t];
    }

    reverse(all(ans));

    for(auto u : ans) cout << u.first << " " << u.second << endl;

}

// --- Think the problem backwards ---

int main()
{
    Baba_Yaga;
    ll tc = 1; //cin >> tc;
    while(tc--) solve();
}
