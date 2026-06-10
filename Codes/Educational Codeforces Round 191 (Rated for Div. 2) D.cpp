// Problem: D. Goods on the Shelf
// Contest: Codeforces - Educational Codeforces Round 191 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2233/problem/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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
	auto check=[&](vector<int>& vec) -> bool {
		map<int,int> mp;
		mp[vec[0]]=1;
		for(int i=1;i<n;i++) {
			if (vec[i-1] == vec[i]) continue;
			if (mp[vec[i]]) return 0;
			else mp[vec[i]]=1;
		}
		
		int cnt=0;
		for(int i=0;i<n;i++) {
			if (vec[i] != a[i]) cnt++;
		}
		return cnt <= 2;
	};
	
	if (check(a)) {cout<<"YES\n";return;}
	
	auto work=[&](int n1,int n2) -> bool {
		int c1=0,c2=0;
		vector<bool> mark(n);
		for(int i=0;i<n;i++) {
			if (a[i] == n1) mark[i]=1,c1++;
			if (a[i] == n2) mark[i]=1,c2++;
		}
		
		int cc1=c1,cc2=c2;
		auto b1=a;
		for(int i=0;i<n;i++) {
			if (mark[i] and cc1) b1[i]=n1,cc1--;
			else if (mark[i] and cc2) b1[i]=n2,cc2--;
		}
		cc1=c1,cc2=c2;
		auto b2=a;
		for(int i=0;i<n;i++) {
			if (mark[i] and cc2) b2[i]=n2,cc2--;
			else if (mark[i] and cc1) b2[i]=n1,cc1--;
		}
		
		// cout<<"!!!\n";
		return check(b1) or check(b2);
	};
	
	map<int,int> mp;
	mp[a[0]]=1;
	int num1=-1,num2=-1;
	for(int i=1;i<n;i++) {
		if (a[i-1] == a[i]) continue;
		
		if (mp[a[i]] and num1 == -1) num1=a[i];
		else if (mp[a[i]] and a[i] != num1 and num2 == -1) num2=a[i];
		else mp[a[i]]=1; 
	}
	
	if (num2 == -1) {
		bool ok=0;
		for(int i=0;i<n;i++) {
			if (a[i] == num1) {
				if (i > 0 and a[i-1] != num1 and work(num1,a[i-1])) ok=1;
				if (i < n-1 and a[i+1] != num1 and work(num1,a[i+1])) ok=1; 
			}
		}
		if (ok) cout<<"YES\n";
		else cout<<"NO\n";
	}
	else {
		if (work(num1,num2)) cout<<"YES\n";
		else cout<<"NO\n";
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	cin>>t;
	while (t--)
		solve();
	return 0;
}







