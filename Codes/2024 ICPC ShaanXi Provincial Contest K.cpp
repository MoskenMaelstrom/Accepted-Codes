#include<bits/stdc++.h>
#define int long long
using namespace std;
int b[20];
void solve()
{
	int n,x;
	cin>>n>>x;
	if (n == 0) {cout<<1<<"\n";return;}
	vector<int> a;
	int n1=n;
	while (n1) {
		a.push_back(n1%10);
		n1/=10;
	}
	
	int ans=0;
	auto dfs=[&](auto&& self,int pos,bool limit) -> int {
		if (pos == -1) return 0;
		int res=0;
		if (!limit) {
			if (a[pos] >= x) res+=(a[pos]-1)*b[pos];
			else res+=(a[pos])*b[pos];
			return res;
		}
		else {
			res+=self(self,pos-1,1)+self(self,pos,0);
			return res;
		}
	};
	cout<<dfs(dfs,a.size()-1,1)+1<<"\n";
}
signed main()
{
	b[0]=1;
	for(int i=1;i<20;i++) b[i]=b[i-1]*9;
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int _=1;
	cin>>_;
	while(_--) solve();
}