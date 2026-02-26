#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int> a(n+5),b(n+5);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	
	vector< array<int,2> > e;//0放数据，1放表示
	for(int i=0;i<n;i++) {
		e.push_back({a[i],0});
		e.push_back({b[i],1});
	}
	sort(e.begin(),e.end());
	
	int ans=0;
	int lst=-1;
	int cntk=0;
	int cnt=n;
	for(auto [x,i] : e) { //x是从小到大的复杂度是O(n)
		 if (x > lst and cntk <= k) ans=max(ans,x*(cnt+cntk));
		 lst=x;
		 if (!i) {cnt--;cntk++;}
		 else cntk--;
	}
	cout<<ans<<endl;
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










