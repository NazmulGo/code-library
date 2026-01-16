int dx[] = {0, 0, 1, -1, 1, -1, -1, 1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

ll n, m;
bool vis[N][N];
char arr[N][N];

bool valid(int i, int j) {
    return (i >= 1 && i <= n && j >= 1 && j <= m && !vis[i][j] && arr[i][j] != '#');
}

void dfs(ll x, ll y) {
    vis[x][y] = true;
    for(int z=0; z<4; z++) {
        ll i = x + dx[z];
        ll j = y + dy[z];
        
        if(valid(i, j)) dfs(i, j);
    }
}
