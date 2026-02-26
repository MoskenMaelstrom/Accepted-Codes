// Problem: 
//     P2216 [HAOI2007] 理想的正方形
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2216
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=1e9;
int arr[1005][1005];//a*b
int arr1[1005][1005];//a*(b-n+1)
int arr2[1005][1005];//(a-n+1)*(b-n+1) 存最大值
int arr3[1005][1005];//a*(b-n+1)
int arr4[1005][1005];//(a-n+1)*(b-n+1) 存最小值
signed main()
{
	int a,b,n;//a=1000 n=100
	cin>>a>>b>>n;
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) cin>>arr[i][j];
	
	//处理arr1
	for(int i=1;i<=a;i++) {
		multiset<int> st;
		for(int j=1;j<=n;j++) st.insert(arr[i][j]);
		arr1[i][1]=*(--st.end());
		for(int j=n+1;j<=b;j++) {
			auto it=st.find(arr[i][j-n]);
			st.erase(it);
			st.insert(arr[i][j]);
			arr1[i][j-n+1]=*(--st.end());
		}
	}
	
	//处理arr2
	for(int j=1;j<=b-n+1;j++) {
		multiset<int> st;
		for(int i=1;i<=n;i++) st.insert(arr1[i][j]);
		arr2[1][j]=*(--st.end());
		for(int i=n+1;i<=a;i++) {
			auto it=st.find(arr1[i-n][j]);
			st.erase(it);
			st.insert(arr1[i][j]);
			arr2[i-n+1][j]=*(--st.end());
		}
	}
	
	//处理arr3
	for(int i=1;i<=a;i++) {
		multiset<int> st;
		for(int j=1;j<=n;j++) st.insert(arr[i][j]);
		arr3[i][1]=*(st.begin());
		for(int j=n+1;j<=b;j++) {
			auto it=st.find(arr[i][j-n]);
			st.erase(it);
			st.insert(arr[i][j]);
			arr3[i][j-n+1]=*(st.begin());
		}
	}
	
	//处理arr4
	for(int j=1;j<=b-n+1;j++) {
		multiset<int> st;
		for(int i=1;i<=n;i++) st.insert(arr3[i][j]);
		arr4[1][j]=*(st.begin());
		for(int i=n+1;i<=a;i++) {
			auto it=st.find(arr3[i-n][j]);
			st.erase(it);
			st.insert(arr3[i][j]);
			arr4[i-n+1][j]=*(st.begin());
		}
	}
	
	//计算ans
	int ans=MAXN;
	for(int i=1;i<=a-n+1;i++) for(int j=1;j<=b-n+1;j++) ans=min(ans,arr2[i][j]-arr4[i][j]);
	cout<<ans;
	return 0;
}






