#include<bits/stdc++.h>

using i32 = int;
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long
#define LINF LLONG_MAX
#define IINF INT_MAX
using namespace std;

int p=1e9+7;
bool yes(vector<int> b)
{
	for(int i=1;i<10;i++) if (b[i] > 1) return 0;
	return 1;
}

int jc(int x)
{
	int res=1;
	for(int i=2;i<=x;i++) {
		res*=i;
		res%=p;
	}
	return res;
}

void solve()
{
	int ans=1;
	int n;
	cin>>n;
	vector<string> a(3);
	for(int i=0;i<3;i++) cin>>a[i];
	vector<int> cnt(n);//记录每列有效的?个数
	for(int j=0;j<n;j++) {
		for(int i=0;i<3;i++) {
			if (a[i][j] == '?') cnt[j]++;
		}
	}
	
	bool ok=1;
	
	//判定1
	set<int> all[3];//记录每组已有的元素
	for(int j=0;j<n;j++) {
		int id=j%3;
		for(int i=0;i<3;i++) {
			if (a[i][j] != '?') all[id].insert(a[i][j]-'0');
		}
	}
	for(int i=0;i<3;i++) {
		if (all[i].size() > 3) {ok=0;break;}
		for(int j=i;j<n;j+=3) {
			int k=3-all[i].size();//k代表允许的?的最大个数
			if (cnt[j] == 2 and j >= 3) ans*=2,ans%=p;
			if (cnt[j] == 3 and j >= 3) ans*=6,ans%=p;
			if (cnt[j] > k and j < 3) {
				if (cnt[j] == 3 and k <= 1) ans*=6,ans%=p;
				if (cnt[j] == 3 and k == 2) ans*=3,ans%=p;
				if (cnt[j] == 2) ans*=2,ans%=p;
				cnt[j]=k;
			}
		}
	}
	
	//判定2
	set<int> st;
	for(int i=0;i<3;i++) {
		for(auto e1 : all[i]) {
			if (st.contains(e1)) {ok=0;break;}
			st.insert(e1);
		}
	}
	
	//判定3
	vector<int> b(10);
	for(int j=0;j<3;j++) {
		for(int i=0;i<3;i++) {
			if (a[i][j] != '?') b[a[i][j]-'0']++;
		}
	}
	if (!yes(b)) ok=0;
	for(int j=3;j<n;j++) {
		for(int i=0;i<3;i++) if (a[i][j-3] != '?') b[a[i][j-3]-'0']--;
		for(int i=0;i<3;i++) if (a[i][j] != '?') b[a[i][j]-'0']++;
		if (!yes(b)) ok=0;
	}
	if (!ok) {cout<<"0\n";return;}
	
	//计算
	ans*=(jc(cnt[0]+cnt[1]+cnt[2]));
	ans%=p;
	cout<<ans<<endl;
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









