#include <bits/stdc++.h>
using namespace std;

const int maxn = 1001;
int t, n, u, v, parent[maxn];
vector<int> adj[maxn];
bool visited[maxn];

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i : adj[v])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
                parent[i] = v;
            }
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
        cout << "0";
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
        cout << i << " ";
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
            if (x == 1 and i < j)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
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
        bfs(u);
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