#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
#define pll pair<ll, ll>
#define endl "\n" 
#define all(v) v.begin(), v.end()
const int N = 1e5+5;

vll w, v;
ll dp[101][N];

ll goo(ll i, ll weightNow) {
    if(i == 0) return 0;
    if(dp[i][weightNow] != -1) return dp[i][weightNow];
    if(weightNow >= w[i-1]) {
       return dp[i][weightNow] = max( goo(i-1, weightNow - w[i-1]) + v[i-1], goo(i-1, weightNow));
    }
    else return dp[i][weightNow] = goo(i-1, weightNow);
}

void solve() {
    memset(dp, -1, sizeof(dp));
    ll n, k; 
    cin >> n >> k;
    v.resize(n), w.resize(n);
    for(int i=0; i<n; i++) {
        ll a, b; cin >> a >> b;
        w[i] = a, v[i] = b;
    }

    cout << goo(n, k) << endl;
}

// --- Try to formulate equations. ---

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    cout.tie(0);

    ll tc = 1; // cin >> tc;
    while(tc--) {
        solve();
    }
}
