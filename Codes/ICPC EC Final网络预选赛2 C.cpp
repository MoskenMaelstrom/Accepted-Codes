#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> f(8);
	for(int i=1;i<=7;i++) cin>>f[i];
	vector<int> vec(4);
	vec[1]+=f[1];
	vec[2]+=f[2];
	vec[3]+=f[4];
	
	auto check=[&](int x) {
		auto a=vec;
		bool ok=0;
		int n12=f[3],n13=f[5],n23=f[6],n123=f[7];
		
		if (n12 != 0) {
			if (a[1] < x and a[1]+n12 < x) a[1]+=n12,n12=0;
			else if (a[1] < x and a[1]+ n12 >= x) n12-=x-a[1],a[1]+=x-a[1];
			
			if (a[2] < x and a[2]+n12 < x) a[2]+=n12,n12=0;
			else if (a[2] < x and a[2]+ n12 >= x) n12-=x-a[2],a[2]+=x-a[2];
		}
		if (n13 != 0) {
			if (a[1] < x and a[1]+n13 < x) a[1]+=n13,n13=0;
			else if (a[1] < x and a[1]+ n13 >= x) n13-=x-a[1],a[1]+=x-a[1];
			
			if (a[3] < x and a[3]+n13 < x) a[3]+=n13,n13=0;
			else if (a[3] < x and a[3]+ n13 >= x) n13-=x-a[3],a[3]+=x-a[3];
		}
		if (n23 != 0) {
			if (a[2] < x and a[2]+n23 < x) a[2]+=n23,n23=0;
			else if (a[2] < x and a[2]+ n23 >= x) n23-=x-a[2],a[2]+=x-a[2];
			
			if (a[3] < x and a[3]+n23 < x) a[3]+=n23,n23=0;
			else if (a[3] < x and a[3]+ n23 >= x) n23-=x-a[3],a[3]+=x-a[3];
		}
		if (n123 != 0) {
			if (a[1] < x and a[1]+n123 < x) a[1]+=n123,n123=0;
			else if (a[1] < x and a[1]+ n123 >= x) n123-=x-a[1],a[1]+=x-a[1];
			
			if (a[2] < x and a[2]+n123 < x) a[2]+=n123,n123=0;
			else if (a[2] < x and a[2]+ n123 >= x) n123-=x-a[2],a[2]+=x-a[2];
			
			if (a[3] < x and a[3]+n123 < x) a[3]+=n123,n123=0;
			else if (a[3] < x and a[3]+ n123 >= x) n123-=x-a[3],a[3]+=x-a[3];
		}
		if (a[1] >= x and a[2] >= x and a[3] >= x) return 1;
		
		a=vec;
		n12=f[3];n13=f[5];n23=f[6];n123=f[7];
		if (n12 != 0) {
			if (a[2] < x and a[2]+n12 < x) a[2]+=n12,n12=0;
			else if (a[2] < x and a[2]+ n12 >= x) n12-=x-a[2],a[2]+=x-a[2];
			
			if (a[1] < x and a[1]+n12 < x) a[1]+=n12,n12=0;
			else if (a[1] < x and a[1]+ n12 >= x) n12-=x-a[1],a[1]+=x-a[1];
		}
		if (n23 != 0) {
			if (a[2] < x and a[2]+n23 < x) a[2]+=n23,n23=0;
			else if (a[2] < x and a[2]+ n23 >= x) n23-=x-a[2],a[2]+=x-a[2];
			
			if (a[3] < x and a[3]+n23 < x) a[3]+=n23,n23=0;
			else if (a[3] < x and a[3]+ n23 >= x) n23-=x-a[3],a[3]+=x-a[3];
		}
		if (n13 != 0) {
			if (a[1] < x and a[1]+n13 < x) a[1]+=n13,n13=0;
			else if (a[1] < x and a[1]+ n13 >= x) n13-=x-a[1],a[1]+=x-a[1];
			
			if (a[3] < x and a[3]+n13 < x) a[3]+=n13,n13=0;
			else if (a[3] < x and a[3]+ n13 >= x) n13-=x-a[3],a[3]+=x-a[3];
		}
		if (n123 != 0) {
			if (a[1] < x and a[1]+n123 < x) a[1]+=n123,n123=0;
			else if (a[1] < x and a[1]+ n123 >= x) n123-=x-a[1],a[1]+=x-a[1];
			
			if (a[2] < x and a[2]+n123 < x) a[2]+=n123,n123=0;
			else if (a[2] < x and a[2]+ n123 >= x) n123-=x-a[2],a[2]+=x-a[2];
			
			if (a[3] < x and a[3]+n123 < x) a[3]+=n123,n123=0;
			else if (a[3] < x and a[3]+ n123 >= x) n123-=x-a[3],a[3]+=x-a[3];
		}
		if (a[1] >= x and a[2] >= x and a[3] >= x) return 1;
		
		a=vec;
		n12=f[3];n13=f[5];n23=f[6];n123=f[7];
		if (n13 != 0) {
			if (a[3] < x and a[3]+n13 < x) a[3]+=n13,n13=0;
			else if (a[3] < x and a[3]+ n13 >= x) n13-=x-a[3],a[3]+=x-a[3];
			
			if (a[1] < x and a[1]+n13 < x) a[1]+=n13,n13=0;
			else if (a[1] < x and a[1]+ n13 >= x) n13-=x-a[1],a[1]+=x-a[1];
		}
		if (n23 != 0) {
			if (a[3] < x and a[3]+n23 < x) a[3]+=n23,n23=0;
			else if (a[3] < x and a[3]+ n23 >= x) n23-=x-a[3],a[3]+=x-a[3];
			
			if (a[2] < x and a[2]+n23 < x) a[2]+=n23,n23=0;
			else if (a[2] < x and a[2]+ n23 >= x) n23-=x-a[2],a[2]+=x-a[2];
		}
		if (n12 != 0) {
			if (a[2] < x and a[2]+n12 < x) a[2]+=n12,n12=0;
			else if (a[2] < x and a[2]+ n12 >= x) n12-=x-a[2],a[2]+=x-a[2];
			
			if (a[1] < x and a[1]+n12 < x) a[1]+=n12,n12=0;
			else if (a[1] < x and a[1]+ n12 >= x) n12-=x-a[1],a[1]+=x-a[1];
		}
		if (n123 != 0) {
			if (a[1] < x and a[1]+n123 < x) a[1]+=n123,n123=0;
			else if (a[1] < x and a[1]+ n123 >= x) n123-=x-a[1],a[1]+=x-a[1];
			
			if (a[2] < x and a[2]+n123 < x) a[2]+=n123,n123=0;
			else if (a[2] < x and a[2]+ n123 >= x) n123-=x-a[2],a[2]+=x-a[2];
			
			if (a[3] < x and a[3]+n123 < x) a[3]+=n123,n123=0;
			else if (a[3] < x and a[3]+ n123 >= x) n123-=x-a[3],a[3]+=x-a[3];
		}
		if (a[1] >= x and a[2] >= x and a[3] >= x) return 1;
		return 0;
	};
	
	int lo=0,hi=1e18,res=-1;
	while (lo <= hi) {
		int mid=lo+hi>>1;
		if (check(mid)) lo=mid+1,res=mid;
		else hi=mid-1;
	}
	
	cout<<res<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;cin>>t;
	while (t--)
		solve();
}