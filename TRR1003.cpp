#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

const int maxn = 1001;
int t, n;
int a[maxn][maxn], res[maxn][maxn], deg[maxn];

void input()
{
    cin >> t >> n;
    vector<pi> e;
    memset(res, 0, sizeof(res));
    memset(deg, 0, sizeof(deg));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 1)
            {
                deg[i]++;
                if (i < j)
                {
                    e.push_back({i, j});
                }
            }
        }
    }
    if (t == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << deg[i] << ' ';
        }
    }
    else
    {
        for (int i = 0; i < e.size(); i++)
        {
            res[e[i].first][i + 1] = 1;
            res[e[i].second][i + 1] = 1;
        }
        cout << n << ' ' << e.size() << "\n";
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= e.size(); j++)
            {
                cout << res[i][j] << ' ';
            }
            cout << endl;
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