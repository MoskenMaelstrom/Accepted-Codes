// Problem: B. Serval and Final MEX
// Contest: Codeforces - Codeforces Round 1011 (Div. 2)
// URL: https://codeforces.com/contest/2085/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
#define LINF LLONG_MAX
#define IINF INT_MAX
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	if (a[0] != 0) {
		set<int> st;
		for(int i=1;i<n;i++) st.insert(a[i]);
		
		if (*st.begin() == 0) {
			cout<<2<<endl;
			cout<<2<<" "<<n<<endl;
			cout<<"1 2"<<endl;
		}
		else {
			cout<<1<<endl;
			cout<<1<<" "<<n<<endl;
		}
	}
	else {
		set<int> st;
		for(int i=2;i<n;i++) st.insert(a[i]);
		
		if (*st.begin() == 0) {
			cout<<3<<endl;
			cout<<"1 2"<<endl;
			cout<<"2 "<<n-1<<endl;
			cout<<"1 2"<<endl;
		}
		else {
			cout<<2<<endl;
			cout<<"1 2"<<endl;
			cout<<"1 "<<n-1<<endl;
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--)
		solve();
	return 0;
}









