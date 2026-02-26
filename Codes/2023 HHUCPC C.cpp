#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

const int N=1e4;
const int p=1e9+7;
void solve()
{
	int k,n;
	cin>>k>>n;
	int siz=0;
	vector<char> a(N+1);
	bool ok=1;
	for(int i=0;i<n;i++) {
		string s;
		cin>>s;
		int m;
		cin>>m;
		while (m--) {
			int p;
			cin>>p;
			siz=max(siz,(int)(p+s.size()-1));
			for(int i=0;i<s.size();i++) {
				if (a[p+i] != 0 and a[p+i] != s[i]) ok=0;
				a[p+i]=s[i];
			}
		}
	}
	
	if (!ok) {cout<<"-1\n";return;}
	
	int cnt=1;
	k--;
	for(int i=siz;i>=1;i--) {
		if (a[i] == 0) cnt*=26,cnt%=p;
		
		if (a[i] == 0) {
			a[i]='a'+k%26;
			k/=26;
		}
	}
	
	cout<<cnt<<"\n";
	for(int i=1;i<=siz;i++) cout<<a[i];
	cout<<"\n";
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







