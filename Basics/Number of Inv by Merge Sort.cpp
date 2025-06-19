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

ll ct = 0;

void merge(ll l1, ll r2) {
    ll mid = (l1+r2)/2;
    ll r1 = mid, l2 = mid+1;
    vll c;
    
    ll i = l1, j = l2;
    while(i <= r1 || j <= r2) {
        if(j == r2+1 || (i <= r1 && v[i] <= v[j])) {
            c.push_back(v[i]);
            i++;
        }
        else {
            ct += (r1-i+1);
            c.push_back(v[j]), j++;
        }
    }
    
    ll k = l1;
    for(int f=0; f<c.size(); f++) {
        v[k] = c[f], k++;
    } 
}

void mergesort(ll l, ll r) {
    if(l == r) return;
    ll mid = (l+r)/2;
    mergesort(l, mid);
    mergesort(mid+1, r);
    merge(l, r);
}

void solve() {
    cin >> n;
    v.resize(n+1);
    for(int i=0; i<n; i++) cin >> v[i];
    mergesort(0, n-1);
    cout << ct << endl;
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
