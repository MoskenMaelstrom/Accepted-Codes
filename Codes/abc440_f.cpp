// Problem: F - Egoism
// Contest: AtCoder - AtCoder Beginner Contest 440
// URL: https://atcoder.jp/contests/abc440/tasks/abc440_f
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
using namespace std;

void solve()
{
	int n,q;
	cin>>n>>q;
	vector<array<int,2>> vec(n);
	int ans=0,c2=0;
	for(int i=0;i<n;i++) {
		cin>>vec[i][0]>>vec[i][1];
		c2+=vec[i][1] == 2;
		ans+=vec[i][0];
	}
	
	multiset<int,greater<int>> st1,st2;
	for(auto [A,B] : vec) {
		if (B == 1) st1.insert(A);
		else st2.insert(A);
	}
	
	multiset<array<int,2>,greater<array<int,2>>> st;
	int r=0,cnt=0;
	for(int i=0;i<c2;i++) {
		if (!st1.empty() and *st1.begin() >= *st2.begin() or 
			!st1.empty() and cnt == 0 and i == c2-1) {
			st.insert({*st1.begin(),1});
			r+=*st1.begin();
			st1.erase(st1.begin());
			cnt++;
		}
		else if (i != c2-1 or cnt) {
			st.insert({*st2.begin(),2});
			r+=*st2.begin();
			st2.erase(st2.begin());
		}
	}
	
	while (q--) {
		int id,a,b;
		cin>>id>>a>>b;
		id--;
		int pa=vec[id][0];
		int pb=vec[id][1];
		vec[id]={a,b};
		ans+=a-pa;
		
		//算c2
		if (pb < b) c2++;
		if (pb > b) c2--;
		
		//删
		if (st.find({pa,pb}) != st.end()) {
			r-=(*st.find({pa,pb}))[0];
			cnt-=pb == 1;
			st.erase(st.find({pa,pb}));
		}
		else if (pb == 1) st1.erase(st1.find(pa));
		else if (pb == 2) st2.erase(st2.find(pa));
		
		//新的待选
		if (b == 1) st1.insert(a);
		else st2.insert(a);
		
		//再删两个最弱的
		if (!st.empty()) {
			auto [A,B]=*st.rbegin();
			r-=A;
			cnt-=B == 1;
			if (B == 1) st1.insert(A);
			else st2.insert(A);
			st.erase(--st.end());
		}
		if (!st.empty()) {
			auto [A,B]=*st.rbegin();
			r-=A;
			cnt-=B == 1;
			if (B == 1) st1.insert(A);
			else st2.insert(A);
			st.erase(--st.end());
		}
		
		for(int i=st.size();i<c2;i++) {
			if (!st1.empty() and *st1.begin() >= *st2.begin() or 
				!st1.empty() and cnt == 0 and i == c2-1) {
				st.insert({*st1.begin(),1});
				r+=*st1.begin();
				st1.erase(st1.begin());
				cnt++;
			}
			else if (i != c2-1 or cnt) {
				st.insert({*st2.begin(),2});
				r+=*st2.begin();
				st2.erase(st2.begin());
			}
		}
		
		cout<<ans+r<<endl;
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







