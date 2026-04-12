// Problem: A. GD 终极节奏实验室
// Contest: Codeforces - The 2025 CCPC National Invitational Contest (Northeast), The 19th Northeast Collegiate Programming Contest
// URL: https://codeforces.com/gym/105924/problem/A
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int ans=0;
	int l=0,r=0;
	for(int i=0;i<n;i++) {
		if (i != 0 and a[i] == a[i-1]) {ans+=--r;continue;}
		
		l=1,r=1;
		for(int j=i-1;j>=0;j--) {
			if (a[j]%a[i] or a[j] == a[i]) break;
			l++;
		}
		for(int j=i+1;j<n;j++) {
			if (a[j]%a[i]) break;
			r++;
		}
		ans+=l*r;
	}
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







