#include<bits/stdc++.h>
using namespace std;
void solve()
{
	string s;
	cin>>s;
	int n=s.length();
	for(int i=0;i<n;i++) {
		if (s[i] == 'q') s.replace(i,1,"p");
		else if (s[i] == 'p') s.replace(i,1,"q");
	}
	for(int i=0;i<n;i++) {
		cout<<s[n-1-i];
	}
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