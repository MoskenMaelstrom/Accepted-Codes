// Problem: E. Greatest Common Divisor
// Contest: Codeforces - The 15th Shandong CCPC Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/105930/problem/E
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

const int N=2e6;
int cnt[N+1];
void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	int maxn=0,sum=0;
	for(int i=0;i<n;i++) {
		cin>>a[i];
		maxn=max(maxn,a[i]);
		sum+=a[i];
		cnt[a[i]]++;
	}
	for(int i=1;i<=2*maxn;i++) cnt[i]+=cnt[i-1];
	
	int ans=1;
	for(int g=2;g<=maxn;g++) {
		if ((k+sum)%g) continue;
		int cur=0;
		for(int l=0;l<maxn;l+=g) {
			int r=l+g;
			cur+=(cnt[r]-cnt[l])*r;
		}
		if (cur-sum > k) continue;
		ans=g;
	}
	
	for(int g=1;g<=(sum+k)/g;g++) {
		if ((sum+k)%g) continue;
		int gg=(sum+k)/g;
		if (g > maxn and g*n-sum <= k) ans=max(ans,g);
		if (gg > maxn and gg*n-sum <= k) ans=max(ans,gg);
	}
	cout<<ans<<"\n";
	
	for(int i=1;i<=2*maxn;i++) cnt[i]=0;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;cin>>t;
	while (t--)
		solve();
	return 0;
}







