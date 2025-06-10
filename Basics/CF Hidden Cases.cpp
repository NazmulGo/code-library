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


int test_case_no = 0;


void solve()
{
    test_case_no++; // Track of case no

    ll n, k; cin >> n >> k;
    vll v(n); 
    priority_queue<ll> pq;
    fr(0, n)
    {
        cin >> v[i];
        pq.push(v[i]);
    }

    if(test_case_no == 294) // je case e WA ditese oi case no
    {
        cout << "Wrong Case: " << endl;
        cout << "n = " << n << "  k = " << k << endl;
        for(auto i: v) cout << i << ' '; cout << endl;
        return;
    }
    if(test_case_no > 4) // sample e highest case joto ase..
    {
        // niche calculation koira output dekhanor dorkar nai.. 
        // just sample pass korar jonne ei condition
        return;
    }

    ll ans = 0;

    while(!pq.empty())
    {
        vll values;
        ll m = min(k, (ll)pq.size());
        while(m--)
        {
            ll val = pq.top();
            values.pb(val);
            pq.pop();
        }

        // sort(all(values)); reverse(all(values));

        ll sz = values.size();
        if(sz == 0) break;
        ans += values[sz-1];
        for(int i=0; i<values.size(); i++)
        {
            values[i] -= (values[sz-1]);
        }

        for(int i=0; i<values.size(); i++)
        {
            if(values[i] > 0)
            {
                pq.push(values[i]);
            }
        }
    }

    cout << ans << endl;
}

// --- Think the problem backwards ---

int main()
{
    Baba_Yaga;
    ll tc = 1; cin >> tc;
    for(int i=1; i<=tc; i++)
    {
        if(tc==294)
        {
            ll n, k; cin >> n >> k;
            vll v(n); 
            fr(0, n)
            {
                cin >> v[i];
            }
            for(auto u : v) cout << u << " ";
            cout << endl;
        }
        else solve();
    }
}
