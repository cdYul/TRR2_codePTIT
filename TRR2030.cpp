#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

const int maxn = 1001;
int n, disc[maxn], low[maxn], timer;
vector<int> adj[maxn];
vector<pi> cc;

void dfs(int u, int par)
{
    disc[u] = low[u] = ++timer;
    for (int i : adj[u])
    {
        if (i == par)
            continue;
        if (!disc[i])
        {
            dfs(i, u);
            low[u] = min(low[u], low[i]);
            if (low[i] > disc[u])
            {
                cc.push_back({min(i, u), max(i, u)});
            }
        }
        else
            low[u] = min(low[u], disc[i]);
    }
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
    timer = 0;
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        if (!disc[i])
        {
            dfs(i, -1);
        }
    }
    cout << cc.size() << "\n";
    sort(begin(cc), end(cc));
    for (auto it : cc)
        cout << it.first << ' ' << it.second << "\n";
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