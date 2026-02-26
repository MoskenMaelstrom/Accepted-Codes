#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> a;
int m,n;

bool check(int x)
{
	//每列至少一个>=x
	for(int j=0;j<n;j++) {
		bool flag=0;
		for(int i=0;i<m;i++)
			if (a[i][j] >= x) flag=1;
		if (!flag) return 0;
	}
	//至少一行>=x的元素有两个及以上
	int flag=0;
	for(int i=0;i<m;i++) {
		int cnt=0;
		for(int j=0;j<n;j++) {
			if (a[i][j] >= x) cnt++;
		}
		if (cnt>=2) flag=1;
	}
	if (flag) return 1;
	else return 0;
}

void solve()
{
	cin>>m>>n;
    a.assign(m, vector<int>(n));
	for(int i=0;i<m;i++) 
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	if (m == 1) {ranges::sort(a[0]);cout<<a[0][0]<<endl;return;}
	
	int l=1,r=2;
	while (check(r)) r<<=1;
	while (r-l > 1) {
		int mid=(r+l)>>1;
		if (check(mid)) l=mid;//mid合法,增加l
		else r=mid;
	}
	cout<<l<<endl;
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









