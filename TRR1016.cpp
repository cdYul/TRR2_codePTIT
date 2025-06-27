#include <bits/stdc++.h>
using namespace std;

const int maxn = 1001;
int t, n, m, degin[maxn], degout[maxn];
vector<int> adj[maxn];

void input()
{
    cin >> t >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        degout[x]++;
        degin[y]++;
        adj[x].push_back(y);
    }
    if (t == 1)
    {
        for (int i = 1; i <= n; i++)
            cout << degin[i] << ' ' << degout[i] << "\n";
    }
    else
    {
        cout << n << "\n";
        for (int i = 1; i <= n; i++)
        {
            cout << adj[i].size() << ' ';
            for (int x : adj[i])
            {
                cout << x << ' ';
            }
            cout << "\n";
        }
    }
}

int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
}