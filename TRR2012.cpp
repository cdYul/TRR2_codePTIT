#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1001;
int n;
vector<int> adj[maxn];
bool visited[maxn];
vector<vector<int>> V;

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    vector<int> k;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        k.push_back(v);
        for (int i : adj[v])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    sort(begin(k), end(k));
    V.push_back(k);
}

void inp()
{
    cin >> n;
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
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            bfs(i);
        }
    }
    cout << V.size() << endl;
    for (auto it : V)
    {
        for (auto x : it)
            cout << x << ' ';
        cout << endl;
    }
}

int main()
{
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    inp();
}