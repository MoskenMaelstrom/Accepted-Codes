// Problem: 小红开机厅
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/125955/F
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	int dx=abs(x1-x2);
	int dy=abs(y1-y2);
	int minn=dx+dy;
	
	vector<int> a(n);
	for(int i=0;i<n;i++) {
		int x,y;
		cin>>x>>y;
		int c=abs(x-x1)+abs(y-y1)+abs(x-x2)+abs(y-y2);
		a[i]=c;	
	}
	
	auto b=a;
	ranges::sort(b);
	for(int i=0;i<n;i++) {
		int ans=0;
		int cnt=upper_bound(b.begin(),b.end(),a[i])-lower_bound(b.begin(),b.end(),a[i]);
		if (a[i] == minn) ans=(dx+1)*(dy+1)-2-cnt;
		else ans=a[i]*2-cnt;
		cout<<ans<<" ";
	}
	cout<<"\n";
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







