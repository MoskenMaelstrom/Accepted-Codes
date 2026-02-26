#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
using namespace std;

mt19937_64 rng {chrono::steady_clock::now().time_since_epoch().count()};
int sg1[]={0,0,1,1,2,0,3,1,1,0,3,3,2,2,4,0,5,2,2,3,3,0,1,1,3,0,2,1,1,0,4,5,2,7,4,0,1,1,2,0,3,1,1,0,3,3,2,2,4,4,5,5,2};
int sg2[]={9,3,3,0,1,1,3,0,2,1,1,0,4,5,3,7,4,8,1,1,2,0,3,1,1,0,3,3,2,2,4,4,5,5};
void solve()
{
	int n,m;
	cin>>n>>m;
	map<int,u64> f;
	f[n]=0;
	for(int i=0;i<m;i++) {
		int n1,n2;
		cin>>n1>>n2;
		u64 x=rng();
		f[n1]^=x;
		f[n2]^=x;
	}
	
	map<u64,int> cnt;
	int p=-1;
	u64 val=0;
	for(auto& [id,x] : f) {
		cnt[val]+=id-p-1;
		val^=x;
		p=id;
	}
	
	int ans=0;
	for(auto [e1,e2] : cnt) {
		if (e2 <= 52) ans^=sg1[e2];
		else {
			e2-=52;
			e2%=34;
			ans^=sg2[e2];
		}
	}
	
	cout<<(ans ? "YES" : "NO")<<"\n";
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









