ll polygon_area(vector<pll> &vp) {
    ll sum_1 = 0, sum_2 = 0, n = vp.size(), area = 0;
    for(int i=0; i<n-1; i++) {
        sum_1 += (vp[i].first * vp[i+1].second);
        sum_2 += (vp[i].second * vp[i+1].first);
    }

    area =  sum_1 - sum_2; // div by 2 is actial rule but here asked for 2*area;
    return abs(area);
}

void solve() {
    ll n; cin >> n;
    vector<pll> vp;
    for(int i=0; i<n; i++) {
        ll x, y; cin >> x >> y;
        vp.push_back({x, y});
    }
    vp.push_back({vp[0].first, vp[0].second});
    cout << polygon_area(vp) << endl;
}
