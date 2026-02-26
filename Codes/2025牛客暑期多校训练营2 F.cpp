// Problem: Field of Fire
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/108299/F
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

void solve()
{
	int n,t;
	cin>>n>>t;
	vector<int> a(n);
	for(int i=0;i<n;i++) {
		char c;
		cin>>c;
		a[i]=c-'0';
	}
	
	int maxn=0,p=0;
	for(int i=0;i<n;i++) {
		if (a[i] == 1) {p=i;break;}
	}
	
	int cnt=0,pos;
	for(int i=p;i<n;i++) {
		if (a[i] == 1) {
			if (maxn <= cnt) {
				maxn=cnt;
				pos=i-1;
			}
			cnt=0;
		}
		else cnt++;
	}
	if (maxn <= cnt+p) {
		maxn=cnt;
		pos=p-1;
	}
	if (pos == -1) pos=n-1;
	
	a[pos]=2;
	for(int i=0;i<n;i++) {
		if (a[i] != 1) continue;
		for(int j=1;j<=t and a[(i-j+n)%n] == 0;j++) {
			a[(i-j+n)%n]=3;
		}
		for(int j=1;j<=t and a[(i+j+n)%n] == 0;j++) {
			a[(i+j+n)%n]=3;
		}
	}
	
	int ans=0;
	for(int i=0;i<n;i++) {
		if (a[i] == 0) ans++;
	}
	cout<<ans<<'\n';
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









