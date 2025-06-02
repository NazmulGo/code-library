ll point_location(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    ll cross = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    if (cross == 0) return 0;  // TOUCH / ON THE LINE
    else if (cross > 0) return 1;  // LEFT
    else return -1;  // RIGHT
}

bool isInside(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    
    ll chk = point_location(x1, y1, x2, y2, x3, y3);  // chk == 0, same Line
    if(chk == 0) {
        if(x3 >= min(x1, x2) && x3 <= max(x1, x2) && y3 >= min(y1, y2) && y3 <= max(y1, y2)) return true;
    }
    return false;
}

void solve() {
    ll n, q; cin >> n >> q;
    vector<pll> vp;
    for(int i=0; i<n; i++) {
        ll x, y; cin >> x >> y;
        vp.push_back({x, y});
    }
    vp.push_back({vp[0].first, vp[0].second});

    while(q--) {
        
        ll x1, y1, x2, y2, x3, y3; cin >> x3 >> y3;
        ll x4 = 1e9+9, y4 = y3+5;

        bool boundary = false;
        ll intersect = 0;

        for(int i=0; i<n; i++) {
            x1 = vp[i].first, y1 = vp[i].second, x2 = vp[i+1].first, y2 = vp[i+1].second;
            bool touch = isInside(x1, y1, x2, y2, x3, y3);
            if(touch) boundary = true;

            ll c1 = point_location(x1, y1, x2, y2, x3, y3);
            ll c2 = point_location(x1, y1, x2, y2, x4, y4);
            ll c3 = point_location(x3, y3, x4, y4, x1, y1);
            ll c4 = point_location(x3, y3, x4, y4, x2, y2);

            if(c1 != c2 && c3 != c4) intersect++;
        }

        if(boundary) cout << "BOUNDARY" << endl;
        else if(intersect & 1) cout << "INSIDE" << endl;
        else cout << "OUTSIDE" << endl;

    }

}
