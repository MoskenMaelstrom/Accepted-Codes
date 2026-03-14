// Problem: E. Entering the unknown
// Contest: Codeforces - The 6th Liaoning Provincial Collegiate Programming Contest
// URL: https://codeforces.com/gym/106380/problem/E
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n+1),b(n+1);
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		int num=a[i];
		while (num) {
			b[i]=max(b[i],num%10);
			num/=10;
		}
	}
	
	int ans=0;
	vector<int> pre(n+1);
	for(int i=1;i<=9;i++) {
		ranges::fill(pre,0);
		for(int j=1;j<=n;j++) pre[j]=(pre[j-1]+a[j])%i;
		
		unordered_map<int,int> mp1,mp2;
		int maxb=0;
		mp1[0]=1;
		for(int r=1;r<=n;r++) {
			maxb=max(maxb,b[r]);
			if (b[r] == i) {
				for(auto [x,y] : mp1) mp2[x]+=y;
				mp1.clear();
				ans+=mp2[pre[r]];
			}
			else if (maxb == i) ans+=mp2[pre[r]];
			else if (maxb > i) maxb=0,mp1.clear(),mp2.clear();
			mp1[pre[r]]++;
		}
	}
	cout<<ans<<"\n";
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







