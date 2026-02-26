#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n,k;
	string s;
	cin>>n>>k>>s;
	vector<int> a(26);
	for(auto ele : s) a[ele-'a']++;
	
	int n1=0,n2=0;
	for(auto ele : a) {
		n1+=ele%2;//可用的奇数
		n2+=ele/2;//可用的对数
	}
	int ans=0;
	ans+=n2/k*2;
	n1+=n2%k*2;
	if (n1 >= k) ans++;
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









