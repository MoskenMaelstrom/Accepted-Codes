// Problem: E. Game with Binary String
// Contest: Codeforces - Educational Codeforces Round 175 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2070/problem/E
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

int ans=0;
vector<int> a;

void solve(int l,int r)
{
	if (l == r) return;
	int mid=l+r>>1;
	solve(l,mid);
	solve(mid+1,r);
	
	vector<int> L,R;
	int sum=0;
	for(int i=mid;i>=l;i--) {
		sum+=a[i];
		L.push_back(sum);
	}
	sum=0;
	for(int i=mid+1;i<=r;i++) {
		sum+=a[i];
		R.push_back(sum);
	}
	ranges::sort(L);
	ranges::sort(R); 
	//(num >= 2-ele) or (num+ele == -1)
	for(auto ele : L) {
		ans+=R.end()-lower_bound(R.begin(),R.end(),2-ele);
		ans+=upper_bound(R.begin(),R.end(),-1-ele)-lower_bound(R.begin(),R.end(),-1-ele);
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	int n;
	cin>>n;
	a.assign(n,0);
	for(int i=0;i<n;i++) {
		char c;
		cin>>c;
		if (c == '0') a[i]=1;
		else a[i]=-3;
	}
	solve(0,n-1);
	cout<<ans;
	return 0;
}