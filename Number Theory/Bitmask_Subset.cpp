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
    for (ll i = 0; i < n; i++) cin >> v[i];

    vector<vll> all_subsets;

    for (ll mask = 0; mask < (1 << n); mask++) {
        vll subset;
        for (ll i = 0; i < n; i++) {   // (2 ^ n -1 ) er bitset n ta
            if (mask & (1 << i)) {
                subset.push_back(v[i]);
            }
        }
        all_subsets.push_back(subset);
    }

    // Print all subsets together
    for (auto &subset : all_subsets) {
        cout << "{ ";
        for (auto x : subset) cout << x << " ";
        cout << "}\n";
    }
}

// --- Try to formulate equations. ---

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    cout.tie(0);

    ll tc = 1; cin >> tc;
    while(tc--) {
        solve();
    }
}
