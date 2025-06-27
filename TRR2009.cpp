#include <bits/stdc++.h>
using namespace std;

const int maxn = 1001;
int n;
vector<vector<int>> Divit;
vector<int> adj[maxn], k;
bool visited[maxn];

void dfs(int u)
{
    visited[u] = true;
    k.push_back(u);
    for (int i : adj[u])
    {
        if (!visited[i])
            dfs(i);
    }
}

void tplt()
{
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            k.clear();
            dfs(i);
            Divit.push_back(k);
        }
    }
    cout << Divit.size() << "\n";
    for (auto it : Divit)
    {
        sort(begin(it), end(it));
        for (int i : it)
            cout << i << ' ';
        cout << "\n";
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
            if (x == 1 and i < j)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    tplt();
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