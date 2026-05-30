// Problem: B. Link Summon
// Contest: Codeforces - The 2024 Sichuan Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105222/problem/B
// Memory Limit: 256 MB
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
	vector<int> a(6);
	for(int i=1;i<=5;i++) cin>>a[i];
	int ans=0;
	
	auto work=[&](int& x,int& y) -> void {
		int m=min(x,y);
		ans+=m;
		x-=m;
		y-=m;
	};
	
	ans+=a[3]/2;
	a[3]%=2;
	work(a[1],a[5]);
	work(a[2],a[4]);
	
	if (a[5] == 0) {
		int x=a[1]/2;
		work(x,a[4]);
		a[1]=x*2+a[1]%2;
		if (a[4] == 0) ans+=(a[1]+a[2]*2+a[3]*3)/6;
		else ans+=(a[1]+a[3]+a[4])/3; //1+4+4,3+3
	}
	else {
		int x=a[2]+a[3]+a[4];
		work(x,a[5]);
		ans+=a[5]/2+x/3;
	}
	cout<<ans<<"\n";
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







