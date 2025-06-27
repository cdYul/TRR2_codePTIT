#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

const int maxn = 1001;
int t, n, s;
vector<pi> dscanh;
vector<int> adj[maxn];
bool visited[maxn];

void dfs(int u)
{
    visited[u] = true;
    for (int i : adj[u])
    {
        if (!visited[i])
        {
            dscanh.push_back({min(u, i), max(u, i)});
            dfs(i);
        }
    }
}

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
                dscanh.push_back({min(i, v), max(i, v)});
            }
        }
    }
}

void input()
{
    cin >> t >> n >> s;
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
        dfs(s);
        if (dscanh.size() == n - 1)
        {
            cout << dscanh.size() << "\n";
            for (auto it : dscanh)
                cout << it.first << ' ' << it.second << "\n";
        }
        else
            cout << "0";
    }
    else
    {
        bfs(s);
        if (dscanh.size() == n - 1)
        {
            cout << dscanh.size() << "\n";
            for (auto it : dscanh)
                cout << it.first << ' ' << it.second << "\n";
        }
        else
            cout << "0";
    }
}

int main()
{
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
}