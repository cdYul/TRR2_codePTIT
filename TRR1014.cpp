#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

const int maxn = 1001;
int t, n, res[maxn][maxn], degin[maxn], degout[maxn];

void input()
{
    cin >> t >> n;
    vector<pi> e;
    memset(res, 0, sizeof(res));
    memset(degin, 0, sizeof(degin));
    memset(degout, 0, sizeof(degout));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            if (x == 1)
            {
                degout[i]++;
                degin[j]++;
                e.push_back({i, j});
            }
        }
    }
    if (t == 1)
    {
        for (int i = 1; i <= n; i++)
            cout << degin[i] << ' ' << degout[i] << "\n";
    }
    else
    {
        cout << n << ' ' << e.size() << "\n";
        for (int i = 0; i < e.size(); i++)
        {
            res[e[i].first][i + 1] = 1;
            res[e[i].second][i + 1] = -1;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= e.size(); j++)
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