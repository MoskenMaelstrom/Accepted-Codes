#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int p=998244353;
const int N=1e6;
int jc[N+1];
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	ranges::sort(a);
	int sum=0;
	for(int i=0;i<n;i++) {
		sum-=a[i]*(n-i);
		sum+=a[i]*(i+1);
	}
	
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++) mp[a[i]]++;

	int ans=2;
	if (mp.size() == 1) ans=1;
	for(auto [x,c]:mp) {
		(ans*=jc[c])%=p;
	}
	cout<<sum<<" "<<ans<<"\n";
}

signed main()
{
	jc[0]=1;
	for(int i=1;i<=N;i++) jc[i]=jc[i-1]*i%p;

	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	// int t;cin>>t;
	// while (t--)
		solve();
	return 0;
}







