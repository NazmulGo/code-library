#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
#define pll pair<ll, ll>
#define endl "\n" 
#define all(v) v.begin(), v.end()
const int N = 2e5+123;
const int mod = 1e9+7;


// int go(int i, int curSum) {
//     if(curSum == 0) return 1;
//     if(i == n) return 0;
//     if(dp[i][curSum] != -1) return dp[i][curSum];
//     int cnt = 0;
//     if(curSum >= v[i]) {
//         cnt += (go(i, curSum - v[i]) % mod);
//         cnt += (go(i+1, curSum) % mod);
//     }
//     else {
//         cnt += (go(i+1, curSum) % mod);
//     }
//     return dp[i][curSum] = cnt % mod;;
// } 

void solve() {
    int n, X; cin >> n >> X;
    vector<int> v(n+2);
    for(int i=1; i<=n; i++) cin >> v[i]; 
    vector<vector<int>> dp((n+2), vector<int> (X+2));
    // for(int i=1; i<=n; i++) {
        dp[n+1][0] = 1;
    // }
    for(int i=n; i>=1; i--) {
        for(int j=0; j<=X; j++) {
            if(j >= v[i]) {
                dp[i][j] = ( dp[i][j-v[i]] % mod + dp[i+1][j] % mod) % mod;
            }
            else {
                dp[i][j] = dp[i+1][j] % mod;
            }
        }
    }
    cout << dp[1][X] << endl;
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
