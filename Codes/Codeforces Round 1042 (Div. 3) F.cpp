// Problem: F. Unjust Binary Life
// Contest: Codeforces - Codeforces Round 1042 (Div. 3)
// URL: https://codeforces.com/problemset/problem/2131/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

const int inf=1e18;
void solve()
{
	int n;
	cin>>n;
	string a,b;
	cin>>a>>b;
	a=" "+a;
	b=" "+b;
	vector<int> X(n+1);
	vector<int> Y(n+1);
	int ca=0,cb=0;
	for(int i=1;i<=n;i++) {
		if (a[i] == '1') ca++;
		if (b[i] == '1') cb++;
		X[i]=2*ca-i;
		Y[i]=2*cb-i;
	}
	
	sort(Y.begin()+1,Y.end());
	vector<int> preY(n+1);
	for(int i=1;i<=n;i++) preY[i]+=preY[i-1]+Y[i];
	
	int ans=0;
	for(int i=1;i<=n;i++) {
		int p=lower_bound(Y.begin()+1,Y.end(),-X[i])-Y.begin();
		ans+=(X[i]*(n-p+1)+preY[n]-preY[p-1])-preY[p-1]-X[i]*(p-1);
	}
	cout<<(n*n*(n+1)-ans)/2<<"\n";
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







