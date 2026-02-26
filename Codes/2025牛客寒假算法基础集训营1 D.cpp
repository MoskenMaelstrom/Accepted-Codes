#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
	set<int> st;
	int n;
	cin>>n;
	
	vector<int> a(n);
	for(int i=0;i<n;i++) {
		cin>>a[i];
		st.insert(a[i]);
	}
	
	if (st.size() != 2 or n%2 == 1) {cout<<"No\n";return;}
	
	map<int,int> mp;
	int p=0;
	vector<int> a2(2,0);
	for(auto ele : st) mp[ele]=p++;
	for(int i=0;i<n;i++) a2[mp[a[i]]]++;
	if (a2[0] == a2[1]) cout<<"Yes\n";
	else cout<<"No\n";
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









