// Problem: C. Colorful Segments 2
// Contest: Codeforces - The 2024 CCPC Shandong Invitational Contest and Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105385/problem/C
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

const int p=998244353;
void solve()
{
	int n,k;
	cin>>n>>k;
	vector<array<int,2>> a(2*n);
	for(int i=0;i<n;i++) {
		cin>>a[i*2][0]>>a[i*2+1][0];
		a[i*2+1][0]++;
		a[i*2][1]=1,a[i*2+1][1]=-1;
	}
	
	ranges::sort(a);
	int ans=1;
	for(auto [x,s] : a) {
		k-=s;
		if (s == 1) {
			(ans*=k+1)%=p;
		}
	}
	cout<<ans<<"\n";
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







