#include <bits/stdc++.h>
using namespace std;

const int maxn = 1001;
int n, disc[maxn], low[maxn], timer;
vector<int> adj[maxn];
bool is_cut[maxn];

void dfs(int u, int par)
{
    disc[u] = low[u] = ++timer;
    int child = 0;
    for (int i : adj[u])
    {
        if (i == par)
            continue;
        if (!disc[i])
        {
            child++;
            dfs(i, u);
            low[u] = min(low[u], low[i]);
            if (par != -1 and low[i] >= disc[u])
            {
                is_cut[u] = true;
            }
        }
        else
            low[u] = min(low[u], disc[i]);
    }
    if (par == -1 and child > 1)
        is_cut[u] = true;
}

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            if (i < j and x == 1)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    memset(disc, 0, sizeof(disc));
    memset(low, 0, sizeof(low));
    memset(is_cut, false, sizeof(is_cut));
    timer = 0;
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        if (!disc[i])
        {
            dfs(i, -1);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (is_cut[i])
            v.push_back(i);
    }
    cout << v.size() << "\n";
    for (int i : v)
        cout << i << ' ';
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