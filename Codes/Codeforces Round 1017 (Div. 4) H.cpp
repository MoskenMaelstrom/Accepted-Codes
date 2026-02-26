#include<bits/stdc++.h>

using i32 = int;
#define int long long 
using namespace std;

constexpr int inf=1e9;

void solve()
{
	map<int,vector<int>> idx;
	int n,q;
	cin>>n>>q;
	vector<int> a(n);
	for(int i=0;i<n;i++) {
		cin>>a[i];
		idx[a[i]].push_back(i);
	}
	
	auto findnxt=[&](int p,int k) -> int {
		int c=lower_bound(idx[k].begin(),idx[k].end(),p)-idx[k].begin();
		if(c == idx[k].size()) return inf;
		return idx[k][c];
	};
	
	while (q--) 
	{
		int ans=0;
		int k,l,r;
		cin>>k>>l>>r;
		l--;
		r--;
		int p;
		while (1) {
			p=inf;
			for(int i=1;i<=k/i;i++) {
				if (k%i != 0) continue;
				p=min(p,findnxt(l,k/i));
				p=min(p,findnxt(l,i));
			}
			if (p > r) break;
			ans+=k*(p-l);
			while (k%a[p] == 0) k/=a[p];
			ans+=k;
			l=p+1;
		}
		ans+=(r-l+1)*k;
		cout<<ans<<endl;
	}
}


signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;cin>>t;
	while (t--) 
		solve();
}






