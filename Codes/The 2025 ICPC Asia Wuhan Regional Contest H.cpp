#include<bits/stdc++.h>
#define int long long
using namespace std;

const int inf=(1<<30)-1;
void solve()
{
	int n;
	cin>>n;
	
	int hi,lo;
	cout<<"? "<<0<<endl;
	cin>>hi;
	cout<<"? "<<(1<<30)-1<<endl;
	cin>>lo;
	lo^=(1<<30)-1;
	
	set<int> st;
	st.insert(hi);
	st.insert(lo);
	
	function<void(int,int)> dfs=[&](int l,int r) {
		if (l == r) return;
		if (st.size() == n) return; 
		int b=__lg(l^r);
		int ask=(~r)|((1<<b)-1);
		ask&=inf;
		cout<<"? "<<ask<<endl;
		int num;
		cin>>num;
		num^=ask;
		if (st.find(num) == st.end()) {
			st.insert(num);
			dfs(num,r);
		}
		
		ask=(~l)&~((1<<b)-1);
		ask&=inf;
		cout<<"? "<<ask<<endl;
		cin>>num;
		num^=ask;
		if (st.find(num) == st.end()) {
			st.insert(num);
			dfs(l,num);
		}
	};
	dfs(lo,hi);
	
	cout<<"! ";
	for(auto e1 : st) cout<<e1<<" ";
	cout<<endl;
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







