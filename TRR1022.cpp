#include <bits/stdc++.h>
using namespace std;

const int maxn = 1001;
int t, n, m, a[maxn][maxn], degin[maxn], degout[maxn];

void input()
{
    cin >> t >> n >> m;
    memset(degin, 0, sizeof(degin));
    memset(degout, 0, sizeof(degout));
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        a[u][v] = w;
        degout[u]++;
        degin[v]++;
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
            for (int j = 1; j <= n; j++)
            {
                if (a[i][j] != 10000 and a[i][j] != 0)
                    cout << a[i][j] << ' ';
                else if (i != j)
                    cout << "10000 ";
                else
                    cout << "0 ";
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