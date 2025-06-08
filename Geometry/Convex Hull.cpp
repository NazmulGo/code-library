#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
#define pll pair<ll, ll>
#define endl "\n" 
#define all(v) v.begin(), v.end()
#define fr(x, n) for (int i = x; i < n; ++i)
const int N = 2e5+123;

ll point_location(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    ll cross = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    if (cross == 0) return 0;  // TOUCH / ON THE LINE
    else if (cross > 0) return 1;  // LEFT
    else return -1;  // RIGHT
}

vector<pair<ll, ll>> convex_hull(vector<pair<ll, ll>>p) {
  ll m, k=1, n=p.size(); if(n<=1) return p;
  sort(p.begin(), p.end()); 
  vector<pair<ll, ll>>hull; k=hull.size();

  for(ll i=0; i<n; i++) {
    m = hull.size();
    while( m >= k+2 && point_location(hull[m-2].first, hull[m-2].second, hull[m-1].first, hull[m-1].second, p[i].first, p[i].second) > 0) {  // >=0 dile same point thakle mibe na
      hull.pop_back();                            // mane hoilo p1 and p2 doita same line e 
      m = hull.size();                              // thakle ekta nibe
    }
    hull.push_back(p[i]);
  }

  hull.pop_back(); 
  k=hull.size();

  for(ll i=n-1; i>=0; i--) {
    m = hull.size();
    while(m >= k+2 && point_location(hull[m-2].first, hull[m-2].second, hull[m-1].first, hull[m-1].second, p[i].first, p[i].second)>0) {
      hull.pop_back();
      m = hull.size();
    }
    hull.push_back(p[i]);
  }

  hull.pop_back();
  return hull;
}

void solve() {
    ll n; cin >> n;

    vector<pair<ll, ll>> points(n);
    for (ll i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    vector<pair<ll, ll>> convex = convex_hull(points);

    cout << convex.size() << endl;
    for (auto [x, y] : convex) {
        cout << x << " " << y << endl;
    }
}

// --- Try to formulate equations. ---

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    cout.tie(0);

    ll tc = 1; //cin >> tc;
    while(tc--) {
        solve();
    }
}

