#include <bits/stdc++.h>
using namespace std;
typedef long double ll;
#define vll vector<ll>
#define pll pair<ll, ll>
#define endl "\n" 
#define all(v) v.begin(), v.end()
#define fr(x, n) for (int i = x; i < n; ++i)
const int N = 2e5+123;

#define yes cout << "YES" << endl
#define no cout << "NO" << endl

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

void solve() {
    ll x1, y1, x2, y2, x3, y3, x4, y4; 
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    ll c1 = point_location(x1, y1, x2, y2, x3, y3);
    ll c2 = point_location(x1, y1, x2, y2, x4, y4);
    ll c3 = point_location(x3, y3, x4, y4, x1, y1);
    ll c4 = point_location(x3, y3, x4, y4, x2, y2);

    if((c1 != c2) && (c3 != c4)) return void(yes);

    bool p1 = isTouch(x1, y1, x2, y2, x3, y3);
    bool p2 = isTouch(x1, y1, x2, y2, x4, y4);
    bool p3 = isTouch(x3, y3, x4, y4, x1, y1);
    bool p4 = isTouch(x3, y3, x4, y4, x2, y2);

    if(p1 || p2 || p3 || p4) yes;
    else no;
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
