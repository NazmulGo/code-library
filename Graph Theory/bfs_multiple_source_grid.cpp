#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

#define pb push_back
#define MOD 1000000007
#define vll vector<ll>
#define pll pair<ll, ll>
#define endl "\n"
#define all(v) v.begin(), v.end()
#define mem(a, b) memset(a, b, sizeof(a))
#define co(n) cout << n << endl
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define fr(x, n) for (int i = x; i < n; ++i)
#define fraction(x) cout << fixed << setprecision(x)
#define Baba_Yaga                 \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL);

const double eps = 1e-9;
const int N = 205;

ll gcd(ll a, ll b) { return __gcd(a, b); }
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }

int dx[] = {0, 0, 1, -1, 1, -1, -1, 1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

int n, m;
char arr[N][N];
vector<pair<int, int>> vp;
int lvl_fire[N][N];
int lvl_Jane[N][N];
int move_ = 0, ans = INT_MAX;
bool ok = false;

void bfs_fire()
{
    queue<pair<int, int>> q;
    for (int i = 0; i < vp.size(); i++)
    {
        q.push({vp[i].first, vp[i].second});
        lvl_fire[vp[i].first][vp[i].second] = 0;
    }

    while (!q.empty())
    {
        int i = q.front().first, j = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int ii = i + dx[k];
            int jj = j + dy[k];
            if (lvl_fire[ii][jj] == -1 && arr[ii][jj] != '#' && arr[ii][jj] != 'F' && ii > 0 && jj > 0 && ii <= n && jj <= m)
            {
                lvl_fire[ii][jj] = lvl_fire[i][j] + 1;
                q.push({ii, jj});
            }
        }
    }
}

void bfs_jane(int x1, int x2)
{
    queue<pair<int, int>> q;
    q.push({x1, x2});
    lvl_Jane[x1][x2] = 0;

    while (!q.empty())
    {
        int i = q.front().first, j = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int ii = i + dx[k];
            int jj = j + dy[k];

            if (lvl_Jane[ii][jj] == -1 && arr[ii][jj] == '.' && ii > 0 && jj > 0 && ii <= n && jj <= m)
            {
                lvl_Jane[ii][jj] = lvl_Jane[i][j] + 1;
                q.push({ii, jj});
                if (ii == 1 || ii == n || jj == 1 || jj == m)
                {
                    if (lvl_fire[ii][jj] == -1 || lvl_Jane[ii][jj] < lvl_fire[ii][jj])
                    {
                        ok = true;
                        ans = min(ans, lvl_Jane[ii][jj]);
                    }
                }
            }
        }
    }
}

void solve()
{
    ans = INT_MAX;
    ok = false;
    vp.clear();
    mem(lvl_fire, -1);
    mem(lvl_Jane, -1);

    cin >> n >> m;
    int st = 0, ed = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'F') vp.push_back({i, j});
            if (arr[i][j] == 'J') st = i, ed = j;
        }
    }
    if (st == 1 || st == n || ed == 1 || ed == m)
    {
        cout << 1 << endl;
        return;
    }

    bfs_fire();
    bfs_jane(st, ed);

    if (ok) cout << ans + 1 << endl;
    else cout << "IMPOSSIBLE" << endl;
}

// --- Think the problem backwards ---

int main()
{
    Baba_Yaga;
    ll tc = 1; cin >> tc;
    ll i = 1;
    while (tc--)
    {
        cout << "Case " << i++ << ": ";
        solve();
    }
}
