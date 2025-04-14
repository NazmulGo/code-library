vector<ll> g[N];
bool vis[N];
vector<ll> lvl(N); 

void bfs(int s) 
{
    queue<int> q;
    q.push(s);
    vis[s] = true;
    lvl[s] = 0;

    while (!q.empty()) 
    {
        int u = q.front();
        q.pop();

        for (int v : g[u]) 
        {
            if (!vis[v]) 
            {
                vis[v] = true;
                lvl[v] = lvl[u] + 1;
                q.push(v);
            }
        }
    }
}
