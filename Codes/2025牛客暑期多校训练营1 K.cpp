// Problem: Museum Acceptance
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/108298/K
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
// #define int long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector a(n,vector<int>(0));
	for(int i=0;i<n;i++) {
		int d;
		cin>>d;
		for(int j=0;j<d;j++) {
			int u;
			cin>>u;
			u--;
			a[i].push_back(u);
		}
	}
	
	vector edge(n,vector<array<int,2>>(3));
	for(int ri=0;ri<n;ri++) {
		for(int rj=0;rj<a[ri].size();rj++) {
			int i=a[ri][rj];
			int j=ranges::find(a[i],ri)-a[i].begin();
			edge[ri][rj]={i,(j+1)%a[i].size()};
		}
	}
	
	
	vector ring(n,vector<int>(3,0));
	int r=1;
	vector<int> siz(n+1);
	
	for(int i=0;i<n;i++) {
		set<array<int,2>> st;
		array<int,2> p1={i,0};
		array<int,2> p2=edge[i][0];
		if (ring[p1[0]][p1[1]] != 0) cout<<siz[ring[p1[0]][p1[1]]]<<'\n';
		else {
			ring[p1[0]][p1[1]]=r;
			while (ring[p2[0]][p2[1]] == 0) {
				// cout<<"p1:"<<p1[0]<<" "<<p1[1]<<'\n';
				st.insert({p1[0],p2[0]});
				st.insert({p2[0],p1[0]});
				ring[p2[0]][p2[1]]=r;
				p1=p2;
				p2=edge[p2[0]][p2[1]];
			}
				st.insert({p1[0],p2[0]});
				st.insert({p2[0],p1[0]});
				ring[p2[0]][p2[1]]=r;
				p1=p2;
				p2=edge[p2[0]][p2[1]];
			siz[r]=st.size()/2;
			cout<<siz[r]<<'\n';
			r++;
		}
	}
	
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









