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
const int N = 1e5+123;

ll gcd(ll a,ll b) { return __gcd(a,b); }
ll lcm(ll a,ll b) { return (a*b)/__gcd(a,b); }

int dx[] = {0, 0, +1, -1, +1, +1, -1, -1};
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1};


void solve()
{
   vll arr[N+1];
   for(int i=1; i*i<= N; i++)
   {
    for(int j=i*i; j <= N; j+=i)
    {
        arr[j].pb(i);
        if( (j / i) != i)
        {
            arr[j].pb(j/i);
        }
    }
   }
//    for(int i=1; i<=100; i++)
//    {
//     cout << i << ": ";
//     for(int j=0; j<arr[i].size(); j++)
//     {
//         cout << arr[i][j] << " ";
//     }
//     cout << endl;
//    }
}

// --- Think the problem backwards ---

int main()
{
    Baba_Yaga;
    ll tc = 1; //cin >> tc;
    while(tc--) solve();
}
