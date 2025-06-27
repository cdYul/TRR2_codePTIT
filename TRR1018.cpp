#include <bits/stdc++.h>
using namespace std;

const int maxn = 1001;
int t, n, a[maxn][maxn], degin[maxn], degout[maxn];

void input()
{
    cin >> t >> n;
    memset(a, 0, sizeof(a));
    memset(degin, 0, sizeof(degin));
    memset(degout, 0, sizeof(degout));
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        while (k--)
        {
            int x;
            cin >> x;
            degout[i]++;
            degin[x]++;
            a[i][x] = 1;
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
        cout << n << "\n";
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << a[i][j] << ' ';
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