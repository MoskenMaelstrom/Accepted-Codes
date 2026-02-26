// Problem: 小红打牌
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/125954/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

const int N=2e5;
const int p=998244353;
void solve()
{
	int n;
	cin>>n;
	vector<int> a(N+1);
	for(int i=0;i<n;i++) {
		int num;
		cin>>num;
		a[num]++;
	}
	
	int c2=0,c4=0;
	for(int i=0;i<=N;i++) {
		if (a[i] >= 2) c2++;
		if (a[i] >= 4) c4++;
	}
	
	int ans=0;
	for(int i=0;i<N;i++) {
		if (a[i] < 3 or a[i+1] < 3) continue;
		int n2=c2,n4=c4;
		if (a[i] >= 2 and a[i]-3 < 2) n2--;
		if (a[i+1] >= 2 and a[i+1]-3 < 2) n2--;
		if (a[i] >= 4 and a[i]-3 < 4) n4--;
		if (a[i+1] >= 4 and a[i+1]-3 < 4) n4--;
		
		ans+=n2*(n2-1)/2+n4;
		ans%=p;
	}
	cout<<ans;
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







