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
const int N = 1e6+123;

ll gcd(ll a,ll b) { return __gcd(a,b); }
ll lcm(ll a,ll b) { return (a*b)/__gcd(a,b); }

int dx[] = {0, 0, +1, -1, +1, +1, -1, -1};
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1};

vector<bool> isPrime(N+1, true);
vll primes;

void sieve()
{
    isPrime[0] = isPrime[1] = false;
    ll sq = sqrt(N);
    for(int i=0; i<=sq; i++)
    {
        if(isPrime[i])
        {
            for(int j = i+i; j<=N; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    for(int i=2; i<=N; i++)
    {
       if(isPrime[i]) primes.pb(i);
    }
}

void solve()
{
    ll n ; cin >> n;
    ll ans = 1;
    for(int i=0; i<primes.size(); i++)
    {
        ll p = primes[i];
        if(p*p > n) break;
        if(n % p == 0)
        {
            ll add = 1, power = 1;
            while(n % p == 0)
            {
                ll k = pow(p, power);
                power++;
                add += k;
                n /= p;
            }
            ans *= add;
        }
    }
    if(n > 1)
    {
        ans *= (n+1);
    }
    cout << ans << endl;
}

// --- Think the problem backwards ---

int main()
{
    Baba_Yaga;
    sieve();
    ll tc = 1; cin >> tc;
    while(tc--) solve();
}
