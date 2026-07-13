// Problem: C. 0mar and Alternating Sums
// Contest: Codeforces - Codeforces Round 1108 (Div. 2)
// URL: https://codeforces.com/contest/2246/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int p=1e9+7;
int Pow(int base,int exp) {
	int res=1;
	base%=p;
	for(;exp;exp>>=1) {
		if (exp&1) res*=base,res%=p;
		base*=base,base%=p;
	}
	return res;
}

int Inv(int num) {
	return Pow(num,p-2);
}

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int cnt1=ranges::count(a,-1);
	map<int,int> mp;
	for(int i=0;i<n;i++) {
		if (a[i] == -1) continue;
		mp[a[i]]++;
	}
	
	int sum=1;
	for(auto [k,cnt] : mp) {
		(sum*=Pow(2,cnt-1))%=p;
	}
	// cout<<sum<<"\n";
	if (cnt1 == 0) {cout<<sum<<"\n";return;}
	
	int ans1=Pow(2,cnt1-1)*sum%p;
	// cout<<ans1<<"\n";
	int ans2=0;
	for(auto [k,cnt] : mp) {
		if (!mp.count(k+1)) continue;
		(ans2+=sum)%=p;
	}
	
	(ans2*=Pow(2,cnt1-1))%=p;
	cout<<(ans1+ans2)%p<<"\n";
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







