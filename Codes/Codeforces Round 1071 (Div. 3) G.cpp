// Problem: G. Blackslex and Penguin Migration
// Contest: Codeforces - Codeforces Round 1071 (Div. 3)
// URL: https://codeforces.com/contest/2179/problem/G
// Memory Limit: 256 MB
// Time Limit: 5000 ms
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
	vector<int> dis(n*n+1);
	for(int i=2;i<=n*n;i++) {
		cout<<"? "<<i<<" 1"<<endl;
		int d;
		cin>>d;
		dis[i]=d;
	}
	
	int i1=max_element(dis.begin()+1,dis.end())-dis.begin();
	int n1=dis[i1];
	vector<int> a(n*n+1);
	vector<int> vec;
	for(int i=1;i<=n*n;i++) {
		cout<<"? "<<i<<" "<<i1<<endl;
		int d;
		cin>>d;
		a[i]=d;
		if (d == n-1) vec.push_back(i);
	}
	int i2=vec[0];
	int maxd=0;
	for(int i=1;i<vec.size();i++) {
		cout<<"? "<<vec[i]<<" "<<vec[0]<<endl;
		int d;
		cin>>d;
		if (d > maxd) maxd=d,i2=vec[i];
	}
	
	
	vector<int> b(n*n+1);
	for(int i=1;i<=n*n;i++) {
		cout<<"? "<<i<<" "<<i2<<endl;
		int d;
		cin>>d;
		b[i]=d;
	}

	vector ans(n,vector<int>(n));
	ans[0][0]=i1;
	ans[0][n-1]=i2;
	for(int i=1;i<=n*n;i++) {
		if (i == i1 or i == i2) continue;
		int d1=a[i];
		int d2=b[i];
		
		ans[d1+d2+1-n>>1][d1-(d1+d2+1-n>>1)]=i;
	}
	
	cout<<"!"<<endl;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
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







