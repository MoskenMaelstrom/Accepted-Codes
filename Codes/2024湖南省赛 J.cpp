#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

struct BIT {
	int n;
	vector<int> c;
	BIT(int n) : n(n),c(n+1,0) {}

	void add(int x,int y) {
		for (;x<=n;x+=x&-x) c[x]+=y;
	}

	int query(int x) {
		int res=0;
		for (;x;x-=x&-x) res+=c[x];
		return res;
	}
};

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n+1),b(n+1);
	for(int i=1;i<=n;i++) {
		int x;
		cin>>x;
		a[x]=i;
	}
	for(int i=1;i<=n;i++) {
		int x;
		cin>>x;
		b[x]=i;
	}

	BIT A(n),B(n);
	int ans=0;
	int l=1,r=0;
	while (l <= n) {
		while (r < n and A.query(a[r+1]) == B.query(b[r+1])) {
			A.add(a[r+1],1);
			B.add(b[r+1],1);
			r++;
		}
		ans+=r-l+1;
		A.add(a[l],-1);
		B.add(b[l],-1);
		l++;
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







