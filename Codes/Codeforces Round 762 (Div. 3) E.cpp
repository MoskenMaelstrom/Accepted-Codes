#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n+1,0);//0~n的桶
	for(int i=0;i<n;i++) {
		int num;
		cin>>num;
		a[num]++;
	}

	priority_queue<tuple<int,int>> q;//大顶堆: [数字,可用于移动的数量]
	//0特判
	if (a[0] == 0) {
		cout<<"0 ";
		int t=n;
		while (t--) cout<<"-1 ";
		cout<<"\n";
		return;
	}
	else cout<<a[0]<<" ";
	if (a[0] > 1) q.push({0,a[0]-1});
	
	int sum=0;
	int allcnt=0;
	for(int i=1;i<=n;i++) {
		//判断可行性
		sum+=a[i-1];//sum代表前面所有的数字的和;
		if (sum <= i and a[i] == 0) {
			cout<<allcnt<<" ";
			int t=n-i;
			while (t--) cout<<"-1 ";
			cout<<"\n";
			return;
		}
		//如果这个元素刚好是0,那直接输出目前的allcnt就行
		if (a[i] == 0) {
			cout<<allcnt<<" ";
			auto [num,cnt]=q.top();
			q.pop();
			cnt--;
			allcnt+=i-num;
			if (cnt != 0) q.push({num,cnt});
		} else {
			cout<<allcnt+a[i]<<" ";
			if (a[i] > 1) q.push({i,a[i]-1});
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
	while (t--)
		solve();
	return 0;
}









