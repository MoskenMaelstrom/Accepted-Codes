#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
	int n,m;
	cin>>n;
	vector<int> a(n+5,0);
	for(int i=1;i<=n;i++) cin>>a[i];
	
	set<int> st; for(int i=1;i<=n;i++) st.insert(a[i]);
	unordered_map<int,int> f;
	int num=1;
	for(auto ele : st) f[ele]=num++;
	vector<int> tong(n+5,0);
	for(int i=1;i<=n;i++) tong[f[a[i]]]++;//记录每种语言会的人的数量
	
	cin>>m;
	vector<int> b(m+5);
	vector<int> c(m+5);
	for(int i=1;i<=m;i++) cin>>b[i];
	for(int i=1;i<=m;i++) cin>>c[i];
	
	int ansi=1,ansn1=0,ansn2=0;
	for(int i=1;i<=m;i++) {
		int cnt1=0;//记录非常满意
		int cnt2=0;//记录几乎满意
		if (f.find(b[i]) != f.end()) cnt1+=tong[f[b[i]]];
		if (f.find(c[i]) != f.end()) cnt2+=tong[f[c[i]]];
		if (cnt1 > ansn1 or cnt1 == ansn1 and cnt2 > ansn2) ansi=i,ansn1=cnt1,ansn2=cnt2;
	}
	cout<<ansi<<endl;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	solve();
	return 0;
}