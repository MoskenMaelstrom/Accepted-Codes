#include<bits/stdc++.h>
#define int long long
using namespace std;
// 快速幂函数，计算 (baseexponent)
int mod_exp(int base, int exponent) {
    int result = 1;
    base = base;  // 防止base本身就大于mod

    while (exponent > 0) {
        // 如果 exponent 是奇数，将 base 乘入结果
        if (exponent % 2 == 1) {
            result = (result * base);
        }

        // exponent 是偶数，将 base 平方并减半 exponent
        exponent = exponent >> 1;  // 等价于 exponent /= 2
        base = (base * base);
    }

    return result;
}


void solve()
{
	int n,x;
	cin>>n>>x;
	vector<int> a(32,0);//0~31
	int num=x;
	
	int pos=0;
	while (num > 0) {
		int b=num&1;
		num>>=1;
		if (b == 1) a[pos]=1;
		pos++;
	}
	for(int i=0;i<32;i++) {
		if (a[i] == 0) {pos=i;break;}
	}
	//现在的pos指向最近的0
	int zhi=mod_exp(2,pos)-1;//zhi==000111111 0,1,2,...,zhi-1
	
	if (n == 1) {cout<<x<<endl;return;}
	if (zhi == x) {
		if (n < zhi and mod_exp(2,pos-1) <= n-1) for(int i=0;i<=n-1;i++) cout<<i<<" ";
		else if (n < zhi) {
			for(int i=0;i<=n-2;i++) cout<<i<<" ";
			cout<<zhi;//5 7 :0,1,2,3,7
		}
		else if (n == zhi){
			for(int i=0;i<=n-1;i++) cout<<i<<" ";
		}
		else { //9 7 : 0,1,2,3,4,5,6,7,0,0
			for(int i=0;i<=zhi;i++) cout<<i<<" ";
			for(int i=0;i<n-zhi-1;i++) cout<<0<<" ";
		}
	}
	
	
	else { 	//x==00001011011 > zhi=011=3
		cout<<x<<" ";
		n--;
		if (n <= zhi) {
			for(int i=0;i<=n-1;i++) cout<<i<<" ";
		}
		else { //7 8 : 0,1,2,3,4,5,6,7
			for(int i=0;i<=zhi;i++) cout<<i<<" ";
			for(int i=0;i<n-zhi-1;i++) cout<<0<<" ";
		}
	}
	cout<<endl;
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









