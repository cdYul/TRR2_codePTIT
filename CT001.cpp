#include <bits/stdc++.h>
using namespace std;

const int maxn = 1001;
int t, n, m, deg[maxn];
set<int> adj[maxn];
bool visited[maxn];

void dfs(int u)
{
    visited[u] = true;
    for (int i : adj[u])
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
}

int lien_thong()
{
    memset(visited, 0, sizeof(visited));
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            cnt++;
            dfs(i);
        }
    }
    return cnt == 1;
}

int isEuler()
{
    if (!lien_thong())
        return 0;
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] % 2)
            res++;
    }
    if (res)
        return 2;
    else
        return 0;
}

void Euler(int u)
{
    stack<int> st;
    vector<int> EC;
    st.push(u);
    while (!st.empty())
    {
        int v = st.top();
        if (adj[v].size() != 0)
        {
            int x = *adj[v].begin();
            st.push(x);
            adj[x].erase(v);
            adj[v].erase(x);
        }
        else
        {
            st.pop();
            EC.push_back(v);
        }
    }
    reverse(begin(EC), end(EC));
    for (int i : EC)
        cout << i << ' ';
}

void input()
{
    cin >> t >> n >> m;
    if (t == 1)
    {
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].insert(y);
            adj[y].insert(x);
            deg[x]++;
            deg[y]++;
        }
        cout << isEuler() << endl;
    }
    else
    {
        int u;
        cin >> u;
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].insert(y);
            adj[y].insert(x);
        }
        Euler(u);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
}