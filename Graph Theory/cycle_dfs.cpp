// "If from a node, I can go to an already visited node that is not its parent, then a cycle exists."
bool hasCycle = false;
void dfs(int u, int parent) 
{
    vis[u] = true;
    for (int v : g[u]) 
    {
        if (!vis[v]) 
        {
            dfs(v, u);
        } 
        else if (v != parent) 
        {
            hasCycle = true;
        }
    }
}
