#include <bits/stdc++.h>
using namespace std;

const int maxn = 1001;
int t, n, u, v, parent[maxn], sl;
vector<int> adj[maxn];
bool visited[maxn];

void dfs(int u)
{
    visited[u] = true;
    for (int i : adj[u])
    {
        if (!visited[i])
        {
            parent[i] = u;
            dfs(i);
        }
    }
}

int CPL(int u, int v)
{
    int cnt = 0;
    for (int i : adj[u])
    {
        for (int j : adj[i])
        {
            if (j == v)
                cnt++;
        }
    }
    return cnt;
}
void Path(int u, int v)
{
    if (!parent[v])
    {
        cout << "0" << "\n";
        return;
    }
    vector<int> path;
    while (v != u)
    {
        path.push_back(v);
        v = parent[v];
    }
    path.push_back(u);
    reverse(begin(path), end(path));
    for (int i : path)
        cout << i << ' ';
    cout << "\n";
}

void input()
{
    cin >> t >> n >> u >> v;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            if (x == 1)
            {
                adj[i].push_back(j);
            }
        }
    }
    memset(visited, false, sizeof(visited));
    if (t == 1)
    {

        cout << CPL(u, v) << "\n";
    }
    else
    {
        dfs(u);
        Path(u, v);
    }
}

int main()
{
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
}