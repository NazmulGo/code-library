#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
#define pll pair<ll, ll>
#define endl "\n" 
#define all(v) v.begin(), v.end()
#define fr(x, n) for (int i = x; i < n; ++i)
const int N = 1010;
#define mem(a,b) memset(a, b, sizeof(a))
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

int dx[] = {0, 0, 1, -1, 1, -1, -1, 1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

bool is_Possible = false;
ll aa = 0, bb = 0;

ll n, m;
char arr[N][N];
bool vis_mon[N][N], vis_me[N][N];
pair<ll,ll>  par_me[N][N];
vector<pll> monsters;
pair<ll, ll> me;
ll lvl_mon[N][N], lvl_me[N][N];

void bfs_monsters() {
    queue<pll> q;
    for(auto [a, b] : monsters) {
        q.push({a, b});
        lvl_mon[a][b] = 0;
        vis_mon[a][b] = true;
    }
    while(!q.empty()) {
        auto [i, j] = q.front();
        q.pop();

        for(int k=0; k<4; k++) {
            ll ii = i + dx[k];
            ll jj = j + dy[k];

            if(ii >= 1 && ii <= n && jj >= 1 && jj <= m && !vis_mon[ii][jj] && arr[ii][jj] != '#' && arr[ii][jj] != 'M') {
                vis_mon[ii][jj] = true;
                q.push({ii, jj});
                lvl_mon[ii][jj] = 1 + lvl_mon[i][j];
            }
        }
    }
}


void bfs_me(ll x, ll y){
    par_me[x][y] = {-1, -1};
    vis_me[x][y] = true;
    lvl_me[x][y] = 0;
    queue<pll> q;
    q.push({x, y});
    while(!q.empty()) {
        auto [i, j] = q.front();
        q.pop();

        for(int k=0; k<4; k++) {
            ll ii = i + dx[k];
            ll jj = j + dy[k];

            if(ii >= 1 && ii <= n && jj >= 1 && jj <= m && !vis_me[ii][jj] && arr[ii][jj] != '#' && arr[ii][jj] != 'M') {
                vis_me[ii][jj] = true;
                q.push({ii, jj});
                par_me[ii][jj] = {i, j};
                lvl_me[ii][jj] = 1 + lvl_me[i][j];
           
                if(is_Possible == false && (ii == 1 || ii == n || jj == 1 || jj == m) && ( lvl_me[ii][jj] < lvl_mon[ii][jj] || lvl_mon[ii][jj] == -1)) {
                    is_Possible = true;
                    aa = ii;
                    bb = jj;
                }
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> arr[i][j];
            lvl_me[i][j] = -1, lvl_mon[i][j] = -1;
            if(arr[i][j] == 'M') monsters.push_back({i, j});
            if(arr[i][j] == 'A') me = {i, j};
        }
    }

    if(me.first == 1 || me.first == n || me.second == 1 || me.second == m) {
        yes;
        cout << 0 << endl;
        return;
    }

    bfs_monsters();
    bfs_me(me.first, me.second);
    if(!is_Possible) return void(no);
    else yes;

    ll x = aa, y = bb;
    string s;
    while(par_me[x][y].first != -1) {
        auto [x1, y1] = par_me[x][y];
        if(x+1 == x1) s.push_back('U');
        else if(x-1 == x1) s.push_back('D');
        else if(y+1 == y1) s.push_back('L');
        else if(y-1 == y1) s.push_back('R');
        x = x1, y = y1;
    }
    reverse(all(s));
    cout << s.size() << endl << s << endl;
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
