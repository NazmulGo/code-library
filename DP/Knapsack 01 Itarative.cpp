#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
#define pll pair<ll, ll>
#define endl "\n" 
#define all(v) v.begin(), v.end()
const int N = 2e5+123;

// ll go(ll i, ll curW) { 
//     if(i == n) return 0;
//     if(dp[i][curW] != -1) return dp[i][curW];
//     ll maxi = 0;
//     if(curW >= weights[i]) {
//         maxi = max(maxi, go(i+1, curW - weights[i]) + val[i]);
//         maxi = max(maxi, go(i+1, curW));
//     }
//     else {
//         maxi = max(maxi, go(i+1, curW));
//     }

//     return dp[i][curW] =  maxi;
// }

void solve() {
    ll n, W; 
    cin >> n >> W;
    vll weights(n+2), val(n+2);
    vector<vll> dp((n+2), vll (W+2));

    for(int i=1; i<=n; i++) {
        cin >> weights[i] >> val[i];
    }

    for(int i=0; i<=W; i++) {
        dp[n+1][i] = 0;
    }

    for(int i=n; i>=1; i--) {
        for(int j=0; j<=W; j++) {
            dp[i][j] = max(dp[i][j], dp[i+1][j]);   // skip weights[i]
            if(j >= weights[i]) {
                dp[i][j] = max(dp[i][j], dp[i+1][j-weights[i]] + val[i]); // take weights[i]
            }
        }
    }

    cout << dp[1][W] << endl;


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
