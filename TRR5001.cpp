#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

const int maxn = 1001;
int n, s, t, d[maxn], parent[maxn];
vector<pi> adj[maxn];

void dijktra(int s)
{
    memset(parent, 0, sizeof(parent));
    priority_queue<pi, vector<pi>, greater<pi>> q;
    for (int i = 1; i <= n; i++)
    {
        d[i] = 1e9;
    }
    d[s] = 0;
    q.push({0, s});
    while (!q.empty())
    {
        pi a = q.top();
        q.pop();
        int u = a.second;
        int du = a.first;
        if (du > d[u])
            continue;
        for (auto i : adj[u])
        {
            int v = i.first;
            int w = i.second;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                parent[v] = u;
                q.push({d[v], v});
            }
        }
    }
}

void input()
{
    cin >> n >> s >> t;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            if (x != 10000 and x != 0)
            {
                adj[i].push_back({j, x});
            }
        }
    }
    dijktra(s);
    if (d[t] != 1e9)
    {
        cout << d[t] << "\n";
        vector<int> path;
        while (t != s)
        {
            path.push_back(t);
            t = parent[t];
        }
        path.push_back(s);
        reverse(path.begin(), path.end());
        for (auto it : path)
            cout << it << ' ';
    }
    else
        cout << "0";
}

int main()
{
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
}