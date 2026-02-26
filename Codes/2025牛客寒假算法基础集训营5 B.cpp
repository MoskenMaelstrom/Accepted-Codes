#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n, t, k;
    cin >> n >> t >> k;
    int s = n - k;
    if (s < t) {
        cout << "0\n";
        return;
    }
    int max_seg = min(s / t, k + 1);
    cout << max_seg << endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--)
		solve();
	return 0;
}









