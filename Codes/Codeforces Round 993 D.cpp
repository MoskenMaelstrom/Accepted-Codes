#include<bits/stdc++.h>
using namespace std;

int a[200005];
bool mark[200005];
void solve()
{
	memset(mark,0,sizeof(mark));
	int n;
	cin>>n;
	stack<int> zhan;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mark[a[i]]=1;
	}
	for(int i=1;i<=n;i++)
		if (!mark[i]) zhan.push(i);
		
	memset(mark,0,sizeof(mark));
	for(int i=1;i<=n;i++) {
		if (mark[a[i]]) {cout<<zhan.top()<<" ";zhan.pop();}
		else {
			mark[a[i]]=1;
			cout<<a[i]<<" ";
		}
	}
	cout<<"\n";
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






