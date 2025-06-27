#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

const int maxn = 1001;
int t, n, m;
int res[maxn][maxn], deg[maxn];

void input()
{
    cin >> t >> n >> m;
    vector<pi> e;
    memset(res, 0, sizeof(res));
    memset(deg, 0, sizeof(deg));
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        e.push_back({x, y});
        deg[x]++;
        deg[y]++;
    }
    if (t == 1)
    {
        for (int i = 1; i <= n; i++)
            cout << deg[i] << ' ';
    }
    else
    {
        for (int i = 0; i < e.size(); i++)
        {
            res[e[i].first][i + 1] = 1;
            res[e[i].second][i + 1] = 1;
        }
        cout << n << ' ' << m << "\n";
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cout << res[i][j] << ' ';
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