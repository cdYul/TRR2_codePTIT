#include <bits/stdc++.h>
using namespace std;

const int maxn = 1001;
int t, n, degin[maxn], degout[maxn];
vector<int> adj[maxn];

void input()
{
    cin >> t >> n;
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
                adj[i].push_back(j);
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
        cout << n << "\n";
        for (int i = 1; i <= n; i++)
        {
            cout << adj[i].size() << ' ';
            for (auto it : adj[i])
                cout << it << ' ';
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