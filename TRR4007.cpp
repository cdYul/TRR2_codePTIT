#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int u, v, w;
};

const int maxn = 1001;
int n, m, parent[maxn], sz[maxn];
vector<edge> adj;

void make_set()
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int a)
{
    if (a == parent[a])
        return a;
    return parent[a] = find(parent[a]);
}

bool Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return false;
    if (sz[a] < sz[b])
        swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
    return true;
}

bool cmp(edge a, edge b)
{
    if (a.w != b.w)
        return a.w < b.w;
    if (a.u != b.u)
        return a.u < b.u;
    return a.v < b.v;
}

void kruskal()
{
    vector<edge> mst;
    int d = 0;
    sort(begin(adj), end(adj), cmp);
    for (int i = 0; i < m; i++)
    {
        if (mst.size() == n - 1)
            break;
        edge e = adj[i];
        if (Union(e.u, e.v))
        {
            mst.push_back(e);
            d += e.w;
        }
    }
    if (mst.size() == n - 1)
    {
        cout << d << "\n";
        for (auto it : mst)
        {
            cout << it.u << ' ' << it.v << ' ' << it.w << "\n";
        }
    }
    else
        cout << "0";
}

void input()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj.push_back({u, v, w});
    }
    make_set();
    kruskal();
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