#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	string s1="uwawauwa";
	int pos1=0,pos2=2;
	
	string s;
	int n;
	cin>>n>>s;
	int cnt=0;
	int ans=0;
	while (pos2 <= n-8) {
		if (s[pos1] == 'u') cnt++;
		if (s.substr(pos2,8) == s1) {
			ans+=cnt;
		}
		pos1++;
		pos2++;
	}
	cout<<ans<<endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--)
		solve();
	return 0;
}









