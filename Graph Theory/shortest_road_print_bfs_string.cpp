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
const int N = 2e5+123;

ll gcd(ll a,ll b) { return __gcd(a,b); }
ll lcm(ll a,ll b) { return (a*b)/__gcd(a,b); }

map<string, vector<string>> adj;
map<string, ll>level;
map<string, string>parent;

void bfs(string source_)
{
    level[source_] = 1;
    queue<string> q;
    q.push(source_);
    while(!q.empty()){
        string u = q.front();
        q.pop();

        for(auto v : adj[u])
        {
            if(level[v] == 0)
            {
                level[v] = level[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

void solve()
{
    ll n; cin >> n;
    for(int i=0; i<n; i++)
    {
        string a, b; cin >> a >> b;
        adj[a].push_back (b);
        adj[b].push_back (a);
    }

    string source_, target_; cin >> source_ >> target_;
    bfs(source_);

    if(level[target_] == 0)
    {
        cout << "No route" << endl;
        return;
    }

    vector<pair<string, string>> ans;

    while( !parent[target_].empty() )
    {
        ans.push_back({parent[target_], target_ });
        target_ = parent[target_];
    }
    reverse(all(ans));
    for(int i=0; i<ans.size(); i++)
    {
        cout << ans[i].first << " " << ans[i].second << endl;
    }

}

// --- Think the problem backwards ---

int main()
{
    Baba_Yaga;
    ll tc = 1; //cin >> tc;
    while(tc--) solve();
}
