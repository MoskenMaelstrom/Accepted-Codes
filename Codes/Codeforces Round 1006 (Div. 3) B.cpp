#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n;
	string s;
	cin>>n>>s;
	int a=count(s.begin(),s.end(),'-');
	int b=n-a;
	cout<<(a/2)*(a-a/2)*b<<endl;
	
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









