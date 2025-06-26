#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
#define pll pair<ll, ll>
#define endl "\n" 
#define all(v) v.begin(), v.end()
const int N = 1e5+1;

ll dp[101][N];

ll n, W;
vll v, weight;

ll go(ll i, ll val) {
    if(val == 0) return 0;
    if(i == n) return 1e16;
    if(dp[i][val] != -1) return dp[i][val];
    ll mini = 1e16;
    if(val >= v[i]) {
        mini = min(mini, go(i+1, val-v[i]) + weight[i]);
    }
    mini = min(mini, go(i+1, val));
    return dp[i][val] =  mini;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> n >> W;
    v.resize(n), weight.resize(n);
    for(int i=0; i<n; i++) {
        cin >> weight[i] >> v[i];
    }

    ll ans = 0;
    for(ll i=0; i<N; i++) {
      ll val = go(0, i);
      if(val <= W) ans = max(ans, i);
    }

    cout << ans << endl;

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
