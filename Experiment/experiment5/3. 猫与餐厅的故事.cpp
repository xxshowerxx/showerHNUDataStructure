#include<bits/stdc++.h>
using namespace std;
vector<set<int>> tree(200000+5);
int a[200000+5];
int ans=0;
int n,m;
void preBfs()
{
	queue<int> bfs;
	bfs.push(1);
	while(!bfs.empty())
	{
		int tmp=bfs.front();
		bfs.pop();
		for(auto it:tree[tmp])
		{
			bfs.push(it);
			tree[it].erase(tmp);
		}
	}
}
void dfs(int i,int maxC,int nowC)
{
	if(a[i]==0)
		nowC=0;
	else
		nowC+=1;
	if(nowC>maxC)
		maxC=nowC;
	if(maxC>m)
		return;
	if(tree[i].empty())
	{
		ans+=1;
		return;
	}
	for(auto it:tree[i])
	{
		dfs(it,maxC,nowC);
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1;i<=n-1;++i)
	{
		int x,y;
		cin>>x>>y;
		tree[x].insert(y);
		tree[y].insert(x);
	}
	preBfs();
	dfs(1,0,0);
	cout<<ans<<endl;
 	return 0;
}

