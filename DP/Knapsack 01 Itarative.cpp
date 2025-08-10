#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
#define pll pair<ll, ll>
#define endl "\n" 
#define all(v) v.begin(), v.end()
const int N = 1e5+5;
 
// int n, x;
// vector<int> cost, pages;
 
// int go(int i, int curVal) {
//     if(i == n) return 0;
 
//     int ans = 0;
//     ans = max(ans, go(i+1, curVal));
//     if(curVal >= cost[i]) ans = max(ans, go(i+1, curVal - cost[i]) + pages[i]);
    
//     return ans;
// }
 
void solve() {
    int n, x; cin >> n >> x;
    
    vector<int> cost(n), pages(n);
    for(int i=0; i<n; i++) cin >> cost[i];
    for(int i=0; i<n; i++) cin >> pages[i];
    
    int dp[1005][N];
    for(int i=0; i<=x; i++) dp[n][i] = 0;
 
    for(int i=n-1; i>=0; i--) {
        for(int j=0; j<=x; j++) {
            dp[i][j] = dp[i+1][j]; // skip 
            if(j >= cost[i]) dp[i][j] = max(dp[i][j], dp[i+1][j-cost[i]] + pages[i]); // take
        }
    }
 
    cout << dp[0][x] << endl;
 
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
