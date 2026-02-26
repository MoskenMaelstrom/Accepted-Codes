// Problem: J. Grand Prix of Ballance
// Contest: Codeforces - 2024 ICPC Asia Chengdu Regional Contest (The 3rd Universal Cup. Stage 15: Chengdu)
// URL: https://codeforces.com/gym/105486/problem/J
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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

void solve()
{
	int n,m,q;
	cin>>n>>m>>q;
	
	vector<array<int,2>> sum(m+1);
	for(int j=1;j<=m;j++) sum[j][1]=j;
	set<int> st;
	int curs=0,cur=0;
	while (q--) {
		int opt;
		cin>>opt;
		if (opt == 1) {
			int id;
			cin>>id;
			st.clear();
			curs=id,cur=m;
		}
		if (opt == 2) {
			int id,x;
			cin>>id>>x;
			if (x != curs or st.find(id) != st.end()) continue;
			st.insert(id);
			sum[id][0]+=cur--;
		}
		if (opt == 3) {
			int id,x;
			cin>>id>>x;
			if (x != curs or st.find(id) != st.end()) continue;
			st.insert(id);
		}
		
	}
	
	sort(sum.begin()+1,sum.end(),[](const array<int,2> a,const array<int,2> b){
		if (a[0] > b[0] or a[0] == b[0] and a[1] < b[1]) return 1;
		return 0;
	});
	for(int i=1;i<=m;i++) cout<<sum[i][1]<<" "<<sum[i][0]<<"\n";
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









