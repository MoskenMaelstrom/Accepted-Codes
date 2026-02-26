#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n,x;
	cin>>n>>x;
	int o=0,a=0;
	while (a < n and (a|x) == x) {
		o|=a;
		a++;
	}
	//不是 (01111 且 01000 00100 00010 00001) 的情况
	if (a == n and o!=x) a--;
	for(int i=0;i<n;i++) {
		cout<<(i < a ? i : x)<<" \n"[i == n-1];
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









