#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
#define pll pair<ll, ll>
#define endl "\n" 
#define all(v) v.begin(), v.end()
const int N = 2e5+123;

ll n;
string s;

ll dp[1001][1001];

ll go(ll l, ll r) {
    if(l == r) return 1;
    if(l > r) return 0;  
    if(dp[l][r] != -1) return dp[l][r];
   
    if(s[l] == s[r]) {
        return dp[l][r] = 2 + go(l+1, r-1);
    }
    else {
        return dp[l][r] = max( go(l+1, r), go(l, r-1));
    }
}

void solve() {

    memset(dp, -1, sizeof(dp));
    cin >> n >> s;

    ll q; cin >> q;
    while(q--) {
        ll l, r; cin >> l >> r;
        l--, r--;
        cout << go(l, r) << endl;
    }

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
