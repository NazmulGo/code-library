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

vll arr[100];
ll color[100];

bool yo = true;
void bfs(ll s)
{
    color[s] = 1;
    queue<ll> q;
    q.push(s);

    while( !q.empty() )
    {
        ll val = q.front();
        q.pop();

        for(auto v : arr[val])
        {
            if(color[v] == 0)
            {
                if(color[val] == 1) color[v] = 2;
                else color[v] = 1;
                q.push(v);
            }
            else if(color[v] == color[val])
            {
                yo = false;
                cout << "NO" << endl;
                return;
            }
            
        }
    }

}

void solve()
{
    ll n; cin >> n;
    for(int i=0; i<n; i++)
    {
        ll a, b; cin >> a >> b;
        arr[a].pb(b);
        arr[b].pb(a);
    }

    bfs(0);
    if(yo) yes;


}

// --- Think the problem backwards ---

int main()
{
    Baba_Yaga;
    ll tc = 1; //cin >> tc;
    while(tc--) solve();
}
