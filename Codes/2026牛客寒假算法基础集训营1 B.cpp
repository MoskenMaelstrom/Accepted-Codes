// Problem: Card Game
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120561/B
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

const int p=998244353;
const int N=1e6;
int jc[N+1];
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	vector<int> b(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	int x=*ranges::min_element(b);
	
	int cnt=0;
	for(auto e1 : a) {
		if (e1 > x) cnt++;
	}
	
	cout<<jc[cnt]*jc[n-cnt]%p<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	jc[0]=1;
	for(int i=1;i<=N;i++) jc[i]=jc[i-1]*i%p;
	int t;cin>>t;
	while (t--)
		solve();
	return 0;
}







