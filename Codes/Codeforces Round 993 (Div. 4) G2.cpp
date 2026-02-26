// Problem: G2. Medium Demon Problem (hard version)
// Contest: Codeforces - Codeforces Round 993 (Div. 4)
// URL: https://codeforces.com/contest/2044/problem/G2
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;


// START: find loops with given functional graph / successor graph (one out-edge for each node).
struct FunctionalGraph {
    int loopN; // 环的数量
    vector<int> loopLen; // 第i个环的长度
    vector<int> loopAnyPoint; // 第i个环的任意某个节点
    vector<int> pointLoopId; // 第i个点属于的环
    vector<int> pointIndexInLoop; // 第i个点在环内的index,没有就返回-1
    vector<bool> pointOnLoop; // 第i个点是否在环内
    vector<int> jointPointOnLoop; // 第i个点在哪个点进入了这个环
    vector<int> distanceToJointPoint; // 第i个点距离jointPointOnLoop的距离
    vector<int> ans;
    int pointN; // number of nodes in graph.
 
    FunctionalGraph(vector<int> &d) {
        pointN = d.size();
        loopN = 0;
        loopLen.assign(pointN, 0);
        loopAnyPoint.assign(pointN, 0);
        pointLoopId.assign(pointN, 0);
        pointOnLoop.assign(pointN, false);
        jointPointOnLoop.assign(pointN, 0);
        distanceToJointPoint.assign(pointN, 0);
        pointIndexInLoop.assign(pointN, -1);
        ans.assign(pointN,0);//只记录在环内的点的外面有几个点
        findLoop(d);
        for(int i=0;i<d.size();i++) {
        	if (!pointOnLoop[i] and pointOnLoop[d[i]]) {
        		ans[i]=dfs(i)+1;
        	}
        }
    }
 	int dfs(int p)
 	{
 		int cnt=0;
 		for(auto e1 : adj[p]) {
 			cnt+=1+dfs(e1);
 		}
 		return cnt;
 	}
    // Sample code.
    // 遍历:
    // void loopInLoop(int head, int[] a) {
    //     for (int x = -1; x != head; x = a[x]) {
    //         if (x == -1) x = head;
    //         // do something.
    //     }
    // }
 
    void findLoop(vector<int> &d) {
        int n = d.size();
        // Arrays.fill(pointLoopId, -1);
        pointLoopId.assign(pointN, -1);//初始化一下,未处理的为-1
        loopN = 0; //记录总共多少个环
        vector<int> t(n, 0);//临时数组
        int tn = 0;
        for (int i = 0; i < n; ++i) {
            if (pointLoopId[i] != -1)
                continue;
            tn = 0;
            int cur = i;
            while (pointLoopId[cur] == -1) {
                pointLoopId[cur] = loopN;
                t[tn++] = cur;
                cur = d[cur];
            }
            //至此,找到了这个点归属于的环,并且对while遍历到的所有点连成的联通块都记录到了t里
            
            //如果这个点归属于已有的环:
            if (pointLoopId[cur] < loopN) {
                int loopId = pointLoopId[cur];
                int jointPoint = jointPointOnLoop[cur];
                for (int j = 0; j < tn; ++j) {
                    pointLoopId[t[j]] = loopId;//说明while里的赋值有问题,需要更新成这个已有的环
                    jointPointOnLoop[t[j]] = jointPoint;
                    distanceToJointPoint[t[j]] = tn - j + distanceToJointPoint[cur];
                }
            } 
            
            //如果这个点归属于新的环:
            else {
                // pointLoopId[cur] ==  loopN
                int loopId = loopN;
                loopAnyPoint[loopId] = cur;
                for (int j = 0; j < tn; j++) {
                    if (t[j] == cur) {
                        loopLen[loopId] = tn - j;
                        break;
                    }
                }
                int idx = 0;
                for (int j = 0; j < tn; j++) {
                    if (tn - j <= loopLen[loopId]) {
                        // in loop
                        pointOnLoop[t[j]] = true;
                        jointPointOnLoop[t[j]] = t[j];
                        pointIndexInLoop[t[j]] = idx++;
                    } else {
                        jointPointOnLoop[t[j]] = cur;
                        distanceToJointPoint[t[j]] = tn - loopLen[loopId] - j;
                    }
                }
                loopN++;//开始找下一个环
            }
        }
        // loopLen = Arrays.copyOf(loopLen, loopN);
        // loopAnyPoint = Arrays.copyOf(loopAnyPoint, loopN);
    }
    
};


	
// END: find loops with given functional graph / successor graph (one out-edge for each point).

void solve()
{
	int n;
	cin>>n;
	adj.assign(n,vector<int>(0));
	vector<int> a(n);
	for(int i=0;i<n;i++) {
		cin>>a[i];
		a[i]--;
		adj[a[i]].push_back(i);
	}
	FunctionalGraph fg(a);
	int ans=0;
	for(int i=0;i<n;i++) {
		ans=max(ans,fg.ans[i]);
	}
	cout<<ans+2<<endl;
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









