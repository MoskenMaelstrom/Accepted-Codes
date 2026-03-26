#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	string s;
	cin>>s;
	vector<int> a(26);
	for(int i=0;i<26;i++) cin>>a[i];
	vector<int> cnt(26);
	int ans=0;
	for(int i=0;i<s.size();i++) {
		cnt[s[i]-'a']++;
		ans+=a[s[i]-'a'];
	}
	cout<<cnt[0];
	for(int i=1;i<26;i++) {
		cout<<" "<<cnt[i];
	}
	cout<<"\n";
	cout<<ans;
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







