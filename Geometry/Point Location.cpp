ll point_location(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    ll m1 = (y2-y1) * (x3-x2);
    ll m2 = (x2-x1) * (y3-y2);
    if(m1 == m2) return 0; // TOUCH
    else if(m1 > m2) return 1; // RIGHT
    else return -1; // LEFT
}

bool isTouch(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    
    ll chk = point_location(x1, y1, x2, y2, x3, y3);  // chk == 0, same Line
    if(chk == 0) {
        if(x3 >= min(x1, x2) && x3 <= max(x1, x2) && y3 >= min(y1, y2) && y3 <= max(y1, y2)) return true;
    }
    return false;
}
