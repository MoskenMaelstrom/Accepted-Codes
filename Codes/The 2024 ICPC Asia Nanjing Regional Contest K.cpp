// Problem: K. Strips
// Contest: Codeforces - The 2024 ICPC Asia Nanjing Regional Contest (The 3rd Universal Cup. Stage 16: Nanjing)
// URL: https://codeforces.com/gym/105484/problem/K
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n,m,k,w;
	cin>>n>>m>>k>>w;
	vector<int> a(n),b(m);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<m;i++) cin>>b[i];
	b.push_back(w+1);
	
	ranges::sort(a);
	ranges::sort(b);
	vector<int> ans;
	auto work=[&](int l,int r) -> int {
		vector<int> vec;
		int p1=ranges::upper_bound(a,l)-a.begin();
		int p2=ranges::upper_bound(a,r)-a.begin()-1;
		if (p2 < p1) return 0;
		
		int cnt=0;
		int nxt=p1;
		while (nxt != a.size() and a[nxt] < r) {
			vec.push_back(a[nxt]);
			cnt++;
			nxt=ranges::lower_bound(a,a[nxt]+k)-a.begin();
		}
		
		if (cnt*k <= r-l-1) {
			while (!vec.empty() and vec.back()+k-1 >= r) {
				int p=vec.back();
				vec.pop_back();
				p=r-k;
				r=p;
				ans.push_back(p);
			}
			for(auto e1 : vec) ans.push_back(e1);
			return cnt;
		}
		else return -1;
	};
	
	int c=0;
	int lst=0;
	for(int i=0;i<b.size();i++) {
		int res=work(lst,b[i]);
		if (res == -1) {cout<<"-1\n";return;}
		else lst=b[i],c+=res;
	}
	cout<<c<<"\n";
	for(auto e1 : ans) cout<<e1<<" ";
	cout<<"\n";
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







