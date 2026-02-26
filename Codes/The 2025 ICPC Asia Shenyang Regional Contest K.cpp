#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n,s;
	cin>>n>>s;
	s--;
	vector<array<int,2>> a(n);
	vector<array<int,2>> b(n);
	
	for(int i=0;i<n;i++) {
		cin>>a[i][0]>>a[i][1];
		cin>>b[i][0]>>b[i][1];
	}
	
	array<int,2> sum1={0,0},sum2={0,0};
	array<int,2> p={a[s][0],a[s][1]};

	for(int i=0;i<n;i++) {
		sum1[0]+=a[i][0];
		sum1[1]+=a[i][1];
		sum2[0]+=b[i][0];
		sum2[1]+=b[i][1];
	}
	
	array<int,2> ans={sum2[0]-sum1[0]>>1,sum2[1]-sum1[1]>>1};
	ans[0]+=p[0];
	ans[1]+=p[1];
	for(int i=0;i<n;i++) {
		if (b[i][0] == ans[0] and b[i][1] == ans[1]) {cout<<i+1;break;}
	}
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







