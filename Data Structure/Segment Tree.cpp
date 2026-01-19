#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
#define pll pair<ll, ll>
#define endl "\n" 
#define all(v) v.begin(), v.end()
const int N = 2e5+123;

ll arr[N], tree[4*N];

void build(ll node, ll l, ll r) {
    if(l == r) {
        tree[node] = arr[l];
        return;
    }

    ll mid = (l+r) / 2;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);

    tree[node] = tree[2*node] + tree[2*node+1];
}

void update(ll node, ll l, ll r, ll i, ll v) {
    if(l == r && l == i) {
        tree[node] = v;
        arr[i] = v;
        return;
    }

    ll mid = (l+r) / 2;
    if(i <= mid) update(2*node, l, mid, i, v);
    else update(2*node+1, mid+1, r, i, v);

    tree[node] = tree[2*node] + tree[2*node+1];
}

ll query(ll node, ll l, ll r, ll i, ll j) {
    if(j < l || r < i) return 0;
    if(i <= l && r <= j) return tree[node];

    ll mid = (l+r) / 2;
    ll left = query(2*node, l , mid, i, j);
    ll right = query(2*node+1, mid+1, r, i, j);

    return left + right;
}

void solve() {
    ll n, q; cin >> n >> q;
    for(int i=1; i<=n; i++) cin >> arr[i];
    build(1, 1, n);

    while(q--) {
        ll typ; cin >> typ;
        if(typ == 1) { // update
            ll i, v; cin >> i >> v;
            update(1, 1, n, i, v);
        }
        else {
            ll i, j; cin >> i >> j;
            cout << query(1, 1, n, i, j) << endl;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    cout.tie(0);

    ll tc = 1; //cin >> tc;
    while(tc--) {
        solve();
    }
}
