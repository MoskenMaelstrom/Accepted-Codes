#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
	const int N=2e5+5;
	vector<int> a(N);
	int n;
	cin>>n;
	for(int i=0;i<n;i++) {
		int x;
		cin>>x;
		a[x]++;
	}
	
	int ans=0;
	for(int i=2;i<=N;i+=2) {
		for(int j=1;j<=i/j;j++) {//一次产生两个因子
			if (i%j != 0) continue;//保证j是i的因子
			int b=(i^j);//计算出b
			if (b < N and b > i and gcd(i,b) == j) ans+=a[i]*a[b];
			
			
			if (j == i/j) continue;
			int J=i/j;
			b=(i^J);//计算出b
			if (b < N and b > i and gcd(i,b) == J) ans+=a[i]*a[b];
		}
	}
	cout<<ans;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	solve();
	return 0;
}









