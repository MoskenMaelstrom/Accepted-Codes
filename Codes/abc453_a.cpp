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
	int p=0;
	for(int i=0;i<n;i++) {
		if (s[i] == 'o') p=i+1;
		else break;
	}
	for(int i=p;i<n;i++) cout<<s[i];
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







