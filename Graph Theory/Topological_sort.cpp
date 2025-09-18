/*
7
6 1
5 1
5 2
4 2
3 4
6 3
*/

ll n;
bool vis[N];
vector<ll> g[N], ans;
stack<ll> st;

void dfs(ll u) {
    vis[u] = true;
    for(auto v : g[u]) {
        if(!vis[v]) {
            dfs(v);
        }
    }
    st.push(u);
}


void solve() {
    cin >> n;
    for(int i=1; i<n; i++) {
        ll u, v; cin >> u >> v;
        g[u].push_back(v);
    }

    for(int i=1; i<=n-1; i++) {
        if(!vis[i]) {
            dfs(i);
        }
    }

    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    for(int i=0; i<ans.size(); i++) cout << ans[i] << " ";
    cout << endl; 

}
