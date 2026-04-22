// Problem: H. Sugar Sweet II
// Contest: Codeforces - The 2023 ICPC Asia Hangzhou Regional Contest (The 2nd Universal Cup. Stage 22: Hangzhou)
// URL: https://codeforces.com/gym/104976/problem/H
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using namespace std;

const int p=1e9+7;
const int N=1e6;
int jc[N+1];
int inv[N+1];
int Pow(int base,int exp) {
	int res=1;
	base%=p;
	for(;exp;exp>>=1) {
		if (exp&1) res*=base,res%=p;
		base*=base,base%=p;
	}
	return res;
}

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n+1),b(n+1),w(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++) cin>>w[i];
	vector<bool> vis(n+1);
	vector<int> P(n+1);
	vector<int> len(n+1);
	for(int i=1;i<=n;i++) {
		if (a[i] < a[b[i]]) vis[i]=1,len[i]=1,P[i]=1;
		else if (a[i] >= a[b[i]]+w[b[i]]) vis[i]=1,len[i]=1,P[i]=0; 
	}
	auto dfs=[&](auto&& self,int u) -> void {
		if (vis[u]) return;
		vis[u]=1;
		int v=b[u];
		if (!vis[v]) self(self,v);
		len[u]=len[v]+1;
		P[u]=P[v]*inv[len[u]]%p;
	};
	
	for(int i=1;i<=n;i++) {
		if (vis[i]) continue;
		dfs(dfs,i);
	}
	
	int ans=0;
	for(int i=1;i<=n;i++) {
		cout<<(a[i]+P[i]*w[i]%p)%p<<" ";
	}
	cout<<"\n";
}

signed main()
{
	jc[0]=1;
	for(int i=1;i<=N;i++) jc[i]=jc[i-1]*i%p;
	inv[1]=1;
	for(int i=2;i<=N;i++) inv[i]=p-inv[p%i]*(p/i)%p;
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;cin>>t;
	while (t--)
		solve();
	return 0;
}







