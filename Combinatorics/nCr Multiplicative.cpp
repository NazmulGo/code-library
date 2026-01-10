ll nCr(ll n, ll r) {
    if(r > n) return 0;
    if(r > n-r) r = n-r;

    ll ans = 1;
    for(int i=1; i<=r; i++) {
        ll val = n - r + i;
        ans = (ans * val) / i;
    }
    return ans;
}
