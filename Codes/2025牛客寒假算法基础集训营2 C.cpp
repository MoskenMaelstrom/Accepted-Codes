// Problem: 字符串外串
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/95334/C
// Memory Limit: 2048 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
#define LINF LLONG_MAX
#define IINF INT_MAX
using namespace std;

void solve()
{
	int n,m;
	cin>>n>>m;
	
	vector<char> a(n+1,'z');
	int hi=n-1,lo=n-26;
	// cout<<hi<<" "<<lo<<endl;
	if (m < lo or m > hi) cout<<"NO\n";
	else {
		cout<<"YES\n";
		if (m >= n/2) {
			int ed=n-m;
			for(int i=1;i<=ed;i++) a[i]='a'-1+i;
			a[ed+1]='a'-1+ed;
			for(int i=n;i>=n/2;i--) a[i]=a[n-i+1];
		}
		else {
			for(int i=1;i<=n-m;i++) a[i]='a'+i-1;
			for(int i=n;i>=m+1;i--) a[i]='a'+n-i;
		}
		
		for(int i=1;i<=n;i++) cout<<a[i];
		cout<<"\n";
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









