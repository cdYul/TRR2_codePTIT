#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int u, v, w;
};

const int maxn = 1001;
int n, s, t, pos, d[maxn], parent[maxn];
vector<edge> adj;

void bellman_ford(int s)
{
    memset(parent, 0, sizeof(parent));
    for (int i = 1; i <= n; i++)
    {
        d[i] = 1e9;
    }
    d[s] = 0;
    for (int i = 1; i <= n; i++)
    {
        pos = -1;
        for (auto e : adj)
        {
            if (d[e.u] != 1e9 and d[e.v] > d[e.u] + e.w)
            {
                d[e.v] = d[e.u] + e.w;
                parent[e.v] = e.u;
                pos = e.v;
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
                adj.push_back({i, j, x});
            }
        }
    }
    pos = -1;
    bellman_ford(s);
    if (d[t] >= 0 and d[t] != 1e9)
    {
        cout << d[t] << "\n";
        vector<int> path;
        while (t != s)
        {
            path.push_back(t);
            t = parent[t];
        }
        path.push_back(s);
        reverse(begin(path), end(path));
        for (auto it : path)
            cout << it << ' ';
        return;
    }
    if (pos != -1)
        cout << "-1";
    else
        cout << "0";
}

int main()
{
    freopen("BN.INP", "r", stdin);
    freopen("BN.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
}