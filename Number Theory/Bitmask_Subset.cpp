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

    vector<vll> subsets;

    for(int mask = 0; mask < (1 << n); mask++) {
        vll sets;
        for(int i=0; i<n; i++) {
            if(mask & (1 << i)) {
                sets.push_back(v[i]);
            }
        }
        subsets.push_back(sets);
    }

    for(auto u : subsets) {
        for(auto x : u) cout << x << " ";
        cout << endl;
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
