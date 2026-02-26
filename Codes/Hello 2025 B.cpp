#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	vector<int> arr=a;
	sort(arr.begin(),arr.end());
	arr.erase(unique(arr.begin(),arr.end()),arr.end());
	for(int i=0;i<n;i++) a[i]=lower_bound(arr.begin(),arr.end(),a[i])-arr.begin()+1;
	
	int kind=arr.size();
	vector<int> tong(n+5,0);
	for(int i=0;i<n;i++) tong[a[i]]++;
	multiset<int> mst;
	for(int i=0;i<n;i++) if (tong[i] != 0) mst.insert(tong[i]);
	for(auto ele : mst) {
		if (k-ele >= 0) k-=ele,kind--;
		else break;
	}
	if (kind > 0) cout<<kind<<endl;
	else cout<<1<<endl;
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


