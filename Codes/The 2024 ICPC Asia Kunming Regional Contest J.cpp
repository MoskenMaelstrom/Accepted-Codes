#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	if (n == 2) {cout<<"Alice\n";return;}

	auto b=a;
	ranges::sort(b);
	int cnt=0;
	for(int i=0;i<n;i++) cnt+=a[i] != b[i];

	if (s[0] == 'A') {
		if (cnt == 2) cout<<"Alice\n";
		else cout<<"Bob\n";
	}
	else {
		if (n == 3 and cnt == 3) cout<<"Alice\n";
		else cout<<"Bob\n";
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;cin>>t;
	while (t--)
		solve();
	return 0;
}







