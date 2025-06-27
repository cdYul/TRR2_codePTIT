#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int u, v, w;
};

const int maxn = 1001;
int t, n, degin[maxn], degout[maxn];

void input()
{
    cin >> t >> n;
    vector<edge> dscanh;
    memset(degin, 0, sizeof(degin));
    memset(degout, 0, sizeof(degout));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            if (x != 10000 and x != 0)
            {
                degout[i]++;
                degin[j]++;
                dscanh.push_back({i, j, x});
            }
        }
    }
    if (t == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << degin[i] << ' ' << degout[i] << "\n";
        }
    }
    else
    {
        cout << n << ' ' << dscanh.size() << "\n";
        for (edge e : dscanh)
        {
            cout << e.u << ' ' << e.v << ' ' << e.w << "\n";
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