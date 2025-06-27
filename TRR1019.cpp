#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

const int maxn = 1001;
int t, n, degin[maxn], degout[maxn];

void input()
{
    cin >> t >> n;
    vector<pi> dscanh;
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
            dscanh.push_back({i, x});
        }
    }
    if (t == 1)
    {
        for (int i = 1; i <= n; i++)
            cout << degin[i] << ' ' << degout[i] << "\n";
    }
    else
    {
        cout << n << " " << dscanh.size() << "\n";
        for (int i = 0; i < dscanh.size(); i++)
        {
            cout << dscanh[i].first << ' ' << dscanh[i].second << "\n";
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