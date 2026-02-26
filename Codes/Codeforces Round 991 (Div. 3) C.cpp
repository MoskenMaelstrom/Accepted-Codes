#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
void solve()
{
	string s;
	cin>>s;
	int a[100005],len=s.length();
	int a2=0,a3=0,sum=0;
	rep(i,len) {a[i]=s[i]-48;sum+=a[i];if (a[i] == 2) a2++; else if (a[i] == 3) a3++;}
	bool flag=0;
	if (sum % 9 == 0) flag=1;
	else if (sum % 9 == 1 and (a2>=4 or a2>=1 and a3>=1)) flag=1;
	else if (sum % 9 == 2 and (a2>=8 or a2>=2 and a3>=2 or a2>=5 and a3>=1)) flag=1;
	else if (sum % 9 == 3 and (a2>=3 or a3>=1)) flag=1;
	else if (sum % 9 == 4 and (a2>=7 or a3>=1 and a2>=4 or a3>=2 and a2>=1)) flag=1;
	else if (sum % 9 == 5 and (a2>=2)) flag=1;
	else if (sum % 9 == 6 and (a2>=6 or a3>=2 or a2>=3 and a3>=1)) flag=1;
	else if (sum % 9 == 7 and (a2>=1)) flag=1;
	else if (sum % 9 == 8 and (a2>=5 or a2>=2 and a3>=1)) flag=1;
	if (flag) cout<<"YES\n";
	else cout<<"NO\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while (t--) solve();
	return 0;
}