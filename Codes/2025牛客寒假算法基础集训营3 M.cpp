#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int a[26]={0};
	for(int i=0;i<8;i++) {
		char c;
		cin>>c;
		a[c-'a']++;
	}
	if (a[2] == 1 and a[3] == 1 and a[4] == 1 and a[13] == 1 and a[14] == 2 and a[17] == 1 and a[22] == 1) cout<<"happy new year";
	else cout<<"I AK IOI";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;
	// cin>>t;
	// while (t--)
		solve();
	return 0;
}









