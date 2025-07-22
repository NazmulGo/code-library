#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
#define pll pair<ll, ll>
#define endl "\n" 
#define all(v) v.begin(), v.end()
const int N = 2e5+123;

ll n, q;
string s;

ll arr[1001][1001];
ll dp[1001][1001];

ll isPalindrome(ll i, ll j) {
    if( i >= j) return 1;
    if(dp[i][j] != -1) return dp[i][j];

    if(s[i] != s[j]) return dp[i][j] = 0;
    else {
       return dp[i][j] = isPalindrome(i+1, j-1);
    }
}

void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> n >> q >> s;
    // for(int i=0; i<n; i++) {
    //     for(int j=i; j<n; j++) {
    //         arr[i][j] = isPalindrome(i, j);
    //     } 
    // }
    while (q--) {
        ll l, r; cin >> l >> r;
        cout << isPalindrome(l, r) << endl;
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
