// Problem: 小红写谱
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/125955/B
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
	vector<int> cnt(9);
	for(int i=0;i<n;i++) {
		int num;
		cin>>num;
		cnt[num]++;
	}
	
	vector<int> a;
	for(int i=1;i<=8;i++) {
		if (cnt[i]) a.push_back(i);
	}
	
	if (a.size() == 1) {cout<<"0\n";return;}
	
	int maxn=0;
	for(int i=0;i<a.size()-1;i++) {
		int x=a[i+1]-a[i];
		maxn=max(x,maxn);
	}
	int ans=max(8-a.back()+a[0],maxn);
	
	cout<<8-ans<<"\n";
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







