// Problem: K. Farm Management
// Contest: Codeforces - 2024 China Collegiate Programming Contest (CCPC) Harbin Onsite (The 3rd Universal Cup. Stage 14: Harbin)
// URL: https://codeforces.com/gym/105459/problem/K
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
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

const int inf=1e18;
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<array<int,3>> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
	
	sort(a.begin()+1,a.end(),greater<array<int,3>>());
	vector<array<int,4>> vec(n+1);
	
	int suml=0;
	int sum0=0;
	for(int i=1;i<=n;i++) {
		suml+=a[i][1];
		sum0+=a[i][0]*a[i][1];
	}
	int rest=m-suml;
	
	for(int i=1;i<=n;i++) {
		vec[i][0]=a[i][0];
		vec[i][1]=a[i][2]-a[i][1];
		vec[i][2]=vec[i-1][2]+vec[i][1];//prenum
		vec[i][3]=vec[i-1][3]+vec[i][0]*vec[i][1];//preval
	}
	
	int res=0;
	for(int i=1;i<=n;i++) {
		int ans=sum0-a[i][0]*a[i][1];
		int rest0=rest+a[i][1];
		auto pre=vec[i];
		vec[i][1]=vec[i][2]=inf;
		int p=lower_bound(vec.begin()+1,vec.begin()+1+i,rest0,[](const array<int,4> x,int val) {
			return x[2] < val;
		}) - vec.begin();
		
		ans+=vec[p-1][3]+(rest0-vec[p-1][2])*vec[p][0];
		vec[i]=pre;
		res=max(res,ans);
	}
	cout<<res;
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









