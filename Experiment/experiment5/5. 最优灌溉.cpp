#include<bits/stdc++.h>
using namespace std;
int ans=0;
int n,m;
int vis[1005],d[1005];
vector<set<pair<int,int>>> adj(1005);
void prim(){
	fill(d,d+1005,100000);
	d[1]=0;
	for(int i=1;i<=n;++i)
	{
		int u=0;
		int min=100000;
		for(int j=1;j<=n;++j)
		{
			if(vis[j]==0&&d[j]<min)
			{
				min=d[j];
				u=j;
			}
		}
		vis[u]=1;
		ans+=d[u];
		for(auto it:adj[u])
		{
			if(vis[it.first]==0&&d[it.first]>it.second)
				d[it.first]=it.second;
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;++i)
	{
		int a,b,c;
		cin>>a>>b>>c;
		adj[a].insert(make_pair(b,c));
		adj[b].insert(make_pair(a,c));
	}
	prim();
	cout<<ans<<endl;
	return 0;
}

