#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
	int n,m;
	cin>>n>>m;
	vector arr(n,vector<int>(m));
	vector<int> b(n);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) cin>>arr[i][j];
		
	vector<int> a(m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) a[j]=arr[i][j];
		sort(a.begin(),a.end());
		b[i]=a[0];
		for(int j=1;j<m;j++) {
			if (a[j] != a[j-1]+n) {cout<<-1<<endl;return;}
		}
	}
	
	map<int,int> mp;
	for(int i=0;i<n;i++) mp[b[i]]=i;
	for(auto ele:mp) cout<<ele.second+1<<" ";
	cout<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--) solve();
	return 0;
}