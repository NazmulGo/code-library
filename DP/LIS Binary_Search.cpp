#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
#define pll pair<ll, ll>
#define endl "\n" 
#define all(v) v.begin(), v.end()
const int N = 2e5+123;

void solve() {
    ll n; cin >> n;
    vll v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    vll ans;
    for(int i=0; i<n; i++) {
        if(ans.empty() || ans.back() < v[i]) {
            ans.push_back(v[i]);
        }
        else{
            ll id = lower_bound(all(ans), v[i]) - ans.begin();
            ans[id] = v[i];
        }
    }    
    // for(int i=0; i<ans.size(); i++)  cout << ans[i] << " ";
    cout << ans.size() << endl;
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
