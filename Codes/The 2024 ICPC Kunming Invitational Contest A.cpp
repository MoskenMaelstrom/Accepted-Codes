// Problem: A. Two-star Contest
// Contest: Codeforces - The 2024 ICPC Kunming Invitational Contest
// URL: https://codeforces.com/gym/105386/problem/A
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
#define int long long

const int inf=1e18;
int n,m,k;
bool cmp(vector<int>& a,vector<int>& b)
{
	if (a[0] != b[0]) return a[0]>b[0];
	else return a[m+1]<b[m+1];
}

void solve()
{
	cin>>n>>m>>k;
	vector a(n,vector<int>(m+2));
	for(int i=0;i<n;i++) {
		for(int j=0;j<=m;j++) {
			cin>>a[i][j];
		}
		a[i][m+1]=i;
	}
	
	sort(a.begin(),a.end(),cmp);
	
	set<int> st;
	st.insert(inf);
	int r=*st.begin();
	for(int i=0;i<n;i++) {
		int cl=0,cr=0,tot=0;
		for(int j=1;j<=m;j++) {
			if (a[i][j] != -1) cr+=a[i][j],cl+=a[i][j],tot+=a[i][j];
			else cr+=k;
		}
		int cur;
		if (i != n-1 and a[i][0] == a[i+1][0]) {
			if (r-1 < cl) {cout<<"No\n";return;}
			if (r-1 < cr) cur=r-1;
			else cur=cr;
			st.insert(cur);
		}
		else {
			if (r-1 < cl) {cout<<"No\n";return;}
			if (r-1 < cr) cur=r-1;
			else cur=cr;
			st.insert(cur);
			r=*st.begin();
		}
		cur-=tot;
		if (cur < 0) {cout<<"No\n";return;}
		for(int j=1;j<=m;j++) {
			if (a[i][j] == -1) {
				if (cur == 0) a[i][j]=0;
				else if (cur >= k) a[i][j]=k,cur-=k;
				else a[i][j]=cur,cur=0;
			}
		}
		if (cur != 0) {cout<<"No\n";return;}
	}
	
	
	
	vector ans(n,vector<int>(m));
	cout<<"Yes\n";
	for(int i=0;i<n;i++) {
		for(int j=1;j<=m;j++) {
			ans[a[i][m+1]][j-1]=a[i][j];
		}
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cout<<ans[i][j]<<" \n"[j == m-1];
		}
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