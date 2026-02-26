// Problem: 
//     P1525 [NOIP2010 提高组] 关押罪犯
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1525
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;

struct human{
	int a1,a2,c;
}p[100005];
bool cmp(human h1,human h2)
{
	return h1.c>h2.c;
}

int f[200005];	//一半为并查集自己,另一半为敌人
int zhao(int num) //返回num的队长
{
	while (f[num] != num) num=f[num];
	return num;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int n,m;
	int a1,a2,c;
	cin>>n>>m;
	rep(i,2*n) f[i]=i;	//一开始所有人队长是他自己
	//最后处理完，所有人都有对应的几个敌人，而f里面某个人指向的敌人实际上并不是这个敌人，
	//而是一种结构(集合)，即f里面的这个人指向的敌人的意义是这个敌人的队长代表的这个敌人的集合
	//所以说其实虽然f里面某个人只指向了一个敌人，但是他其实指向了这个敌人的集合，代表了一堆敌人
	//而我们要做的实际上是通过这个人指向的某个敌人所代表的集合，来变相保存了这个人的敌人，以便于下次操作
	//换句话说，这个人带了一个包，这个包里有着一堆敌人，他随时可以快速查到这个敌人的队长
	//而且，他换一个队伍，这个包仍然跟着他（他依然指向这个包）
	//这样有一个好处，就是这个包可以随着他加入某个集合而并入其他包里，非常方便
	rep(i,m) cin>>p[i].a1>>p[i].a2>>p[i].c;	
	sort(p+1,p+100006,cmp);
	rep(i,m){
		a1=p[i].a1;
		a2=p[i].a2;
		c=p[i].c;
		if (zhao(a1) == zhao(a2)) {cout<<c;return 0;}//如果a1和a2在同一个集合中，直接输出c
		else {
			//把a2放到a1的敌人的集合中，即将a2的队长指向a1的敌人的队长
			f[zhao(a2)]=f[zhao(a1+n)];
			f[zhao(a1)]=f[zhao(a2+n)];
		}
	}
	cout<<0;
	return 0;
}



