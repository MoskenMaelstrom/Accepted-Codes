// Problem: C. Crossing River
// Contest: Codeforces - The 2025 ICPC Asia Chengdu Regional Contest (The 4rd Universal Cup. Stage 4: Grand Prix of Chengdu)
// URL: https://codeforces.com/gym/106161/problem/C
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector<array<int,2>> a(n),b(m);
	for(int i=0;i<n;i++) {
		cin>>a[i][0];
		a[i][1]=i+1;
	}
	for(int i=0;i<m;i++) {
		cin>>b[i][0];
		b[i][1]=i+1;
	}
	ranges::sort(a);
	ranges::sort(b);
	
	for(int i=1;i<n;i++) {
		a[i][0]=max(a[i][0],a[i-1][0]+2*k);
	}
	for(int i=1;i<m;i++) {
		b[i][0]=max(b[i][0],b[i-1][0]+2*k);
	}
	
	if (a[n-1][0] < b[m-1][0]) {
		if (a[n-1][0]+k > b[m-1][0]) b[m-1][0]=a[n-1][0]+k;
		else a[n-1][0]=b[m-1][0]-k;
	}
	else {
		if (b[m-1][0]+k > a[n-1][0]) a[n-1][0]=b[m-1][0]+k;
		else b[m-1][0]=a[n-1][0]-k;
	}
	cout<<max(a[n-1][0],b[m-1][0])+k<<'\n';
	
	vector<array<int,3>> ans;
	for(int i=n-2;i>=0;i--) {
		a[i][0]=a[i+1][0]-2*k;
	}
	for(int i=m-2;i>=0;i--) {
		b[i][0]=b[i+1][0]-2*k;
	}
	
    for (int i=0;i<n;i++) {
        ans.push_back({a[i][0],0,a[i][1]});
    }
    for (int i=0;i<m;i++) {
        ans.push_back({b[i][0],1,b[i][1]});
    }
	ranges::sort(ans);
	for(auto [e1,e2,e3] : ans) cout<<e1<<" "<<e2<<" "<<e3<<"\n";
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







