#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
#define pll pair<ll, ll>
#define endl "\n" 
#define all(v) v.begin(), v.end()

int dx[] = {0, 0, 1, -1, 1, -1, -1, 1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

ll n, m;
const int N = 1005;
char arr[N][N];
bool vis_me[N][N], vis_mon[N][N];
ll lvl_me[N][N], lvl_mon[N][N];
vector<pll> mons, me;
pll par_me[N][N];

bool valid_mon(ll i, ll j) {
    return (i >= 1 && j >= 1 && i <= n && j <= m && !vis_mon[i][j] && arr[i][j] != '#');
}

bool valid_me(ll i, ll j) {
    return (i >= 1 && j >= 1 && i <= n && j <= m && !vis_me[i][j] && arr[i][j] == '.');
}

void bfs_monster() {
    queue<pll> q;
    for(int i=0; i<mons.size(); i++) {
        q.push({mons[i]});
        vis_mon[mons[i].first][mons[i].second] = true, lvl_mon[mons[i].first][mons[i].second] = 1;
    } 

    while(!q.empty()) {
        auto[i, j] = q.front(); q.pop();

        for(int k=0; k<4; k++) {
            ll ni = i + dx[k], nj = j + dy[k];
            if(valid_mon(ni, nj)) {
                q.push({ni, nj});
                lvl_mon[ni][nj] = 1 + lvl_mon[i][j], vis_mon[ni][nj] = true;
            }
        }
    }
}

void bfs_me() {
    queue<pll> q;
    for(int i=0; i<me.size(); i++) {
        q.push({me[i]});
        auto[x, y] = me[i];
        vis_me[x][y] = true, lvl_me[x][y] = 1, par_me[x][y] = {-1, -1};
    } 

    while(!q.empty()) {
        auto[i, j] = q.front(); q.pop();

        for(int k=0; k<4; k++) {
            ll ni = i + dx[k], nj = j + dy[k];
            if(valid_me(ni, nj)) {
                q.push({ni, nj});
                lvl_me[ni][nj] = 1 + lvl_me[i][j], vis_me[ni][nj] = true, par_me[ni][nj] = {i, j};
            }
        }
    }
}

bool valid(ll i, ll j) {
   return (( lvl_me[i][j] != -1) && (lvl_me[i][j] < lvl_mon[i][j] || lvl_mon[i][j] == -1));
}

void solve() {
    
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            lvl_me[i][j] = -1, lvl_mon[i][j] = -1, vis_me[i][j] = false, vis_mon[i][j] = false, par_me[i][j] = {-1, -1};
            cin >> arr[i][j];
            if(arr[i][j] == 'M') mons.push_back({i, j});
            if(arr[i][j] == 'A') me.push_back({i, j});
        }
    }

    bfs_monster();
    bfs_me();
    
    pll ans = {-1, -1};
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(i == 1 || j == 1 || i == n || j == m) {
                if(valid(i, j)) ans = {i, j};
            }
        }
    }

    if(ans.first == -1) {
        cout << "NO" << endl; return;
    }

    string s;

    while(ans.first != -1) {
        auto[i, j] = ans;
        pll par = par_me[i][j];

        if(i+1 == par.first) s.push_back('U');
        if(i-1 == par.first) s.push_back('D');
        if(j+1 == par.second) s.push_back('L');
        if(j-1 == par.second) s.push_back('R');

        ans = par;
    }

    reverse(all(s));
    cout << "YES" << endl;
    cout << s.size() << endl << s << endl;

}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    cout.tie(0);

    ll tc = 1; // cin >> tc;
    while(tc--) {
        solve();
    }
}
