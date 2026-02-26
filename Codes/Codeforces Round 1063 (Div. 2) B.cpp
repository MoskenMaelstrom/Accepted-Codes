// Problem: B. Siga ta Kymata
// Contest: Codeforces - Codeforces Round 1063 (Div. 2)
// URL: https://codeforces.com/contest/2163/problem/B
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

const int inf=1e18;
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	vector<int> p(n);
	for(int i=0;i<n;i++) {
		cin>>a[i];
		a[i]--;
		p[a[i]]=i;
	}
	string s;
	cin>>s;
	int l=p[0],r=p[n-1];
	int ok=1;
	
	for(int i=0;i<n;i++) {
		if (s[i] == '1') {
			if (i == 0 or i == n-1 or i == l or i == r) {ok=0;break;}
		}
	}
	
	if (ok == 0) cout<<"-1\n";
	else {
		cout<<"5\n";
		cout<<min(l,r)+1<<" "<<max(l,r)+1<<"\n";
		cout<<1<<" "<<l+1<<"\n";
		cout<<1<<" "<<r+1<<"\n";
		cout<<l+1<<" "<<n<<"\n";
		cout<<r+1<<" "<<n<<"\n";
	}
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







