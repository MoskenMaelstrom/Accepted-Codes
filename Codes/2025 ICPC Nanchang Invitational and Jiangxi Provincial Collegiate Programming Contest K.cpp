// Problem: K. Rotation
// Contest: Codeforces - 2025 ICPC Nanchang Invitational and Jiangxi Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105911/problem/K
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int c0=0,c1=0,c2=0,c3=0;
	auto calc=[&](int x,int res) -> int {
		if (x < res) x+=4;
		return x-res;
	};
	int ans=1e18;
	int res=0;
	int cnt=0;
	for(int i=0;i<n;i++) {
		int t=calc(a[i],0);
		res+=t;
		cnt+=t;
	}
	ans=min(ans,res+4-((0+cnt+3)%4+1));
	
	res=0,cnt=0;
	for(int i=0;i<n;i++) {
		int t=calc(a[i],1);
		res+=t;
		cnt+=t;
	}
	ans=min(ans,res+4-((1+cnt+3)%4+1));
	
	res=0,cnt=0;
	for(int i=0;i<n;i++) {
		int t=calc(a[i],2);
		res+=t;
		cnt+=t;
	}
	ans=min(ans,res+4-((2+cnt+3)%4+1));
	
	res=0,cnt=0;
	for(int i=0;i<n;i++) {
		int t=calc(a[i],3);
		res+=t;
		cnt+=t;
	}
	ans=min(ans,res+4-((3+cnt+3)%4+1));
	
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







