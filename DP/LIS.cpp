#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
#define pll pair<ll, ll>
#define endl "\n" 
#define all(v) v.begin(), v.end()
const int N = 2e5+123;

ll n;
vll v;
ll dp[2505];

ll go(ll i) {
    if(i == n) return 0;
    if(dp[i] != -1) return dp[i];
    ll ans = 1;
    for(int j=i+1; j<n; j++) {
        if(v[j] > v[i]) {
            ans = max(ans, go(j) + 1);
        }
    }
    return dp[i] = ans;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> n;
    v.resize(n);
    for(int i=0; i<n; i++) cin >> v[i]; 
    for(int i=0; i<n; i++) {
        go(i);
    }
    for(int i=0; i<8; i++) {
        cout << dp[i] << " ";
    }
}

// --- Try to formulate equations. ---

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    cout.tie(0);

    ll tc = 1; //cin >> tc;
    while(tc--) {
        solve();
    }
}
