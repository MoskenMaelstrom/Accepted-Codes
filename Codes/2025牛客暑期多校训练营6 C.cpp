// Problem: Stack
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/108303/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

const int p=998244353;
const int N=5e5;
vector<int> ans(N+1);
void solve()
{
	int n;
	cin>>n;
	cout<<(ans[n]+p)%p<<'\n';
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	vector<int> inv(N+1);
	inv[1]=1;
	for(int i=2;i<=N;i++) {
		inv[i]=p-inv[p%i]*(p/i)%p;
	}
	
	vector<int> jc(N+1);
	jc[0]=1;
	for(int i=1;i<=N;i++) {
	    jc[i]=jc[i-1]*i%p;
	}
	
	vector<int> H1(N+1),H2(N+1),H3(N+1);
	for(int i=1;i<=N;i++) {
		H1[i]=H1[i-1]+inv[i];
		H1[i]%=p;
		H2[i]=H2[i-1]+(inv[i]*inv[i])%p;
		H2[i]%=p;
		H3[i]=H3[i-1]+(inv[i]*inv[i])%p*inv[i]%p;
		H3[i]%=p;
	}
	for(int i=1;i<=N;i++) {
		int h1=H1[i],h2=H2[i],h3=H3[i];
		ans[i]=(h1*h1%p*h1%p+3*h1*h1%p+h1-3*h1%p*h2%p-3*h2+2*h3)%p*jc[i]%p;
	}
	int t;cin>>t;
	while (t--)
		solve();
	return 0;
}









