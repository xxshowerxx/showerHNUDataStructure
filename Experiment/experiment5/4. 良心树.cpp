#include<bits/stdc++.h>
using namespace std;
int p[100000+5];
int c[100000+5];
set<int> eraseNode;
vector<set<int>> tree(100000+5);
void bfs(int root){
	queue<int> q;
	q.push(root);
	while(!q.empty())
	{
		int parent=q.front();
		q.pop();
		int flag=1;
		if(c[parent]==0)
			flag=0;
		for(auto it:tree[parent])
		{
			if(c[it]==0)
				flag=0;
			q.push(it);
		}
		if(flag==1)
			eraseNode.insert(parent);
	}
}
int main()
{
	int n,root=0;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>p[i]>>c[i];
		if(p[i]==-1)
			root=i;
		else
			tree[p[i]].insert(i);
	}
	bfs(root);
	for(auto it:eraseNode)
	{
		cout<<it<<" ";
	}
	if(eraseNode.empty())
		cout<<-1<<endl;
	return 0;
}

