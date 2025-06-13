//https://cses.fi/problemset/task/1193
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
#define pll pair<ll, ll>
#define endl "\n" 
#define all(v) v.begin(), v.end()
#define fr(x, n) for (int i = x; i < n; ++i)
const int N = 1010;

#define yes cout << "YES" << endl
#define no cout << "NO" << endl

int dx[] = {0, 0, 1, -1, 1, -1, -1, 1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

ll n, m;
char arr[N][N];
bool vis[N][N];
pair<ll,ll>  par[N][N];

void bfs(ll x, ll y){
    par[x][y] = {-1, -1};
    vis[x][y] = true;
    queue<pll> q;
    q.push({x, y});
    while(!q.empty()) {
        auto [i, j] = q.front();
        q.pop();

        for(int k=0; k<4; k++) {
            ll ii = i + dx[k];
            ll jj = j + dy[k];

            if(ii >= 1 && ii <= n && jj >= 1 && jj <= m && !vis[ii][jj] && arr[ii][jj] != '#') {
                vis[ii][jj] = true;
                q.push({ii, jj});
                par[ii][jj] = {i, j};
            }
        }
    }
}

void solve() {
    pll st, ed;
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> arr[i][j];
            par[i][j] = {-1, -1};
            if(arr[i][j] == 'A') st = {i, j};
            if(arr[i][j] == 'B') ed = {i, j};
        }
    }

    bfs(st.first, st.second);
    ll x = ed.first, y = ed.second;

    if(!vis[x][y]) return void(no);
    else yes;

      string s;
      while(par[x][y].first != -1) {
         auto [x1, y1] = par[x][y];
         if(x+1 == x1) s.push_back('U');
         else if(x-1 == x1) s.push_back('D');
         else if(y+1 == y1) s.push_back('L');
         else if(y-1 == y1) s.push_back('R');
         x = x1, y = y1;
      }
        reverse(all(s));
     
    cout << s.size() << endl;
    cout << s << endl;
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
