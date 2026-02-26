#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    vector<vector<int>> a1(n, vector<int>(m, 0));
    vector<vector<int>> a2(n, vector<int>(m, 0));
    vector<vector<int>> a3(n, vector<int>(m, 0));
    vector<vector<int>> a4(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            a1[i][j] = a[i][j];
            if (i > 0 && j > 0) {
                a1[i][j] += a1[i - 1][j - 1];
            }
        }

    for (int i = 0; i < n; i++)
        for (int j = m - 1; j >= 0; --j) {
            a2[i][j] = a[i][j];
            if (i > 0 && j < m - 1) {
                a2[i][j] += a2[i - 1][j + 1];
            }
        }

    for (int i = n - 1; i >= 0; --i)
        for (int j = m - 1; j >= 0; --j) {
            a3[i][j] = a[i][j];
            if (i < n - 1 && j < m - 1) {
                a3[i][j] += a3[i + 1][j + 1];
            }
        }

    for (int i = n - 1; i >= 0; --i)
        for (int j = 0; j < m; j++) {
            a4[i][j] = a[i][j];
            if (i < n - 1 && j > 0) {
                a4[i][j] += a4[i + 1][j - 1];
            }
        }

    int sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int cnt = a1[i][j] + a2[i][j] + a3[i][j] + a4[i][j] - 3 * a[i][j];
            sum = max(cnt, sum);
        }

    cout << sum << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
