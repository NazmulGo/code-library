ll n, m;
bool vis[N];
vector<ll> g[N];

void dfs(ll u)
{
    vis[u] = true;
    for(auto v : g[u])
    {
        if(!vis[v])
        {
            dfs(v);
        }
    }
}
