#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int lowbit(int x) {return x & (-x);}

int shu[N];
int n;
void add(int x,int k)	//在x位置加上k，即将x位置即其父节点递归性加k
{
	for(int i=x;i<=n;i+=lowbit(i)) shu[i]+=k;
}

int sum(int x)	//查询x的前缀和
{
	int res=0;
	for(int i=x;i;i-=lowbit(i)) res+=shu[i];
	return res;
}

void solve()
{
	memset(shu,0,sizeof(shu));
	cin>>n;
	vector<int> a(n+5,0);
	vector<int> cha(n+5,0);
	vector<int> b(n+5);	
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	
	for(int i=1;i<=n;i++) cha[i]=a[i]-a[i-1];//计算差分
	for(int i=1;i<=n;i++) add(i,cha[i]);
	for(int i=1;i<=n;i++) {
		int c=sum(i)-b[i];
		if (c < 0) {
			add(1,c);
			add(i,-2*c);
			add(i+1,2*c);
		}
	}
	
	for(int i=1;i<=n;i++) if (sum(i) < b[i]) {cout<<"NO\n";return;}
	cout<<"YES\n";
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