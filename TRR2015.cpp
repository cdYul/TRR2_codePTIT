#include <bits/stdc++.h>
using namespace std;

const int maxn = 1001;
int n;
vector<int> adj[maxn], rev_adj[maxn], divit[maxn];
bool visited[maxn];

void dfs(int u, vector<int> graph[])
{
    visited[u] = true;
    for (int i : graph[u])
    {
        if (!visited[i])
        {
            dfs(i, graph);
        }
    }
}

bool lien_thong_manh()
{
    memset(visited, false, sizeof(visited));
    dfs(1, adj);
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            return false;
    }
    memset(visited, false, sizeof(visited));
    dfs(1, rev_adj);
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            return false;
    }
    return true;
}

bool lien_thong_yeu()
{
    memset(visited, false, sizeof(visited));
    dfs(1, divit);
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            return false;
    }
    return true;
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
            if (x == 1)
            {
                adj[i].push_back(j);
                rev_adj[j].push_back(i);
                divit[i].push_back(j);
                divit[j].push_back(i);
            }
        }
    }
    if (lien_thong_manh())
    {
        cout << "1";
    }
    else if (lien_thong_yeu())
    {
        cout << "2";
    }
    else
        cout << "0";
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