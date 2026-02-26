// Problem: 小红出勤
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/125955/C
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
	int n,p,k;
	cin>>n>>p>>k;
	map<string,int> mp;
	int sum=0;
	for(int i=0;i<n;i++) {
		string s;
		int c;
		cin>>s>>c;
		mp[s]=c;
		sum+=c;
	}
	
	vector<string> vec(k);
	for(int i=0;i<k;i++) {
		string s;
		cin>>s;
		vec[i]=s;
	}
	
	int t=1e9;
	for(auto s : vec) {
		t=min(t,mp[s]);
	}
	
	if (t*p < sum) {
		cout<<"-1\n";
		return;
	}
	else {
		int l=sum/p;
		if (p*l < sum) l++;
		cout<<l<<" "<<t<<"\n";
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







