int dx[] = {0, 0, 1, -1, 1, -1, -1, 1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

int n, m;
char arr[N][N];
bool vis[N][N];
int dist[N][N];
pll parent[N][N];

bool valid(int r, int c) {
    return (r >= 1 && r <= n && c >= 1 && c <= m && !vis[r][c] && arr[r][c] != '#');
}

void bfs(ll sr, ll sc) {
    queue<pll> q;
    q.push({sr, sc});

    vis[sr][sc] = true, dist[sr][sc] = 0, par[sr][sc] = {-1, -1};

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nr = r + dx[d];
            int nc = c + dy[d];

            if (valid(nr, nc)) {
                vis[nr][nc] = true, dist[nr][nc] = dist[r][c] + 1, parent[nr][nc] = {r, c};
                q.push({nr, nc});
            }
        }
    }
}
