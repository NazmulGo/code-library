// https://cses.fi/problemset/task/1192/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
#define endl "\n" 
const int N = 1005;

int dx[] = {0, 0, 1, -1, 1, -1, -1, 1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

ll n, m; 
bool vis[N][N];
char arr[N][N];

void dfs(ll x, ll y) {
    vis[x][y] = true;
    
    for(int z=0; z<4; z++) {
        ll i = x + dx[z];
        ll j = y + dy[z];

        if(i >= 1 && i <= n && j >= 1 && j <= m && !vis[i][j] && arr[i][j] != '#') {
            dfs(i, j);
        }
    }
}


void solve() {
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> arr[i][j];
        }
    }

    ll score = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(!vis[i][j] && arr[i][j] != '#') {
                score++;
                dfs(i, j);
            }
        }
    }
    cout << score << endl;

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
