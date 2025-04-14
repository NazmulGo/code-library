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
const int N = 2e5+123;

ll gcd(ll a,ll b) { return __gcd(a,b); }
ll lcm(ll a,ll b) { return (a*b)/__gcd(a,b); }

int dx[] = {0, 0, +1, -1, +1, +1, -1, -1};
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1};

ll n, m;
bool vis[N];
vector<ll> arr[N];

bool dfs(ll k)
{
    vis[k] = true;
    for(auto u : arr[k])
    {
        if(!vis[u])
        {
            dfs(u);
        }
    }

}
void solve()
{
    cin >> n >> m;
    for(int i=1; i<=m; i++)
    {
        ll u, v; cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    ll connected_component = 0;
    for(ll i=1; i<=n; i++)
    {
        if(vis[i] == 0)
        {
            connected_component++;
            dfs(i);
        }
    }

   cout << connected_component << endl;

}

// --- Think the problem backwards ---

int main()
{
    Baba_Yaga;
    ll tc = 1; // cin >> tc;
    while(tc--) solve();
}
