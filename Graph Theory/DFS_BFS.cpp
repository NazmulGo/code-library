
vector<ll> g[N]; 
vector<bool> vis;
vll par, lvl;

//For Test Case
void g_clear(int n){
    for(int i=0; i<=n; i++) g[i].clear();
    par.assign(n+1, -1);
    lvl.assign(n+1, -1);
    vis.assign(n+1, false);
}


//DFS
void dfs(ll u) {
    vis[u] = true;
    for(auto v : g[u]) {
        if(!vis[v]) dfs(v);
    }
}

//BFS
void bfs(int s) {
    queue<int> q;
    q.push(s);
    vis[s] = true, lvl[s] = 0, par[s] = s;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (!vis[v]) {
                vis[v] = true, lvl[v] = lvl[u] + 1, par[v] = u;
                q.push(v);
            }
        }
    }
}
