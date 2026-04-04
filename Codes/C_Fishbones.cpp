#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

bool f[11][11][26];
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++) cin>>a[i]>>b[i];
	int m;
	cin>>m;
	vector<string> s(m);
	for(int i=0;i<m;i++) {
		cin>>s[i];
		int len=s[i].size();
		for(int j=0;j<len;j++) {
			f[len][j+1][s[i][j]-'a']=1;
		}
	}

	for(int i=0;i<m;i++) {
		string cur=s[i];
		if (s[i].size() != n) {
			cout<<"No\n";
			continue;
		}
		bool ok=1;
		for(int j=0;j<n;j++) {
			if (f[a[j]][b[j]][cur[j]-'a'] == 0) {ok=0;break;}
		}
		if (ok) cout<<"Yes\n";
		else cout<<"No\n";
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;cin>>t;
	// while (t--)
		solve();
	return 0;
}







