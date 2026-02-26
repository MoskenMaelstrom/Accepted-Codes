#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
	int n;
	cin>>n;
	vector<int> L(n),R(n);
	multiset<tuple<int,int,int>> a;//左界, 右界, 序号
	multiset<tuple<int,int>> b;//序号, rank
	for(int i=0;i<n;i++) {
		cin>>L[i]>>R[i];
		a.insert( {L[i],R[i],i} );
	}
	int num=1;//从1开始
	multiset<tuple<int,int,int>> st;//临时的a
	while (!a.empty()) {
		auto [l,r,N]=*a.begin();
		
		if (num >= l) {
			st.insert({r,l,N});
			a.erase(a.begin());
		} else {
			if (st.begin() != st.end()) {
				auto [a1,a2,a3]=*st.begin();
				b.insert( {a3,num++} );
				st.erase(st.begin());
			}
			else {cout<<-1;return;}
		}
		
	}
	
	for(auto &[r,l,N] : st) b.insert( {N,num++} );
	for(auto &[i,rk] : b)
		if (rk < L[i] or rk > R[i]) {cout<<-1;return;}
	for(auto &[_,rk] : b) cout<<rk<<" ";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	solve();
	return 0;
}









