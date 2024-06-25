#include<bits/stdc++.h>
using namespace std;
long long int a[2*1000+5][2*1000+5];
int n,m,w;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
struct Channel{
	long long int weight=LONG_LONG_MAX;
}channel[2];//D到通道最短距离与S到通道最短距离 
long long int mark[2*1000+5][2*1000+5][2]={0};
long long ans=LONG_LONG_MAX; 
void bfs(int x,int y,int type){
	queue<pair<int,int>> q;
	q.push(pair<int,int>(x,y));
	mark[x][y][0]=1;
	while(!q.empty()){
		pair<int,int> tmp=q.front();
		q.pop();
		if(type==-1&&tmp.first==n&&tmp.second==m  //直接能走到终点的情况
		&& ans>mark[tmp.first][tmp.second][1]) //更新ans 
		{
			ans=mark[tmp.first][tmp.second][1];
			return;
		}
		if(type!=-1&&a[tmp.first][tmp.second]!=0&&channel[type].weight>(long long)(mark[tmp.first][tmp.second][1]+a[tmp.first][tmp.second]))
			channel[type].weight=mark[tmp.first][tmp.second][1]+a[tmp.first][tmp.second];
		//更新到通道最短距离 
		if(mark[tmp.first][tmp.second][1]<0)
			return;
		if(type!=-1)
		{
			if(mark[tmp.first][tmp.second][1]>=channel[type].weight)
				return;
			if(a[tmp.first][tmp.second]!=0&&w>a[tmp.first][tmp.second])
				continue;
		}
		//剪枝，以及防止数据溢出 
		for(int i=0;i<4;++i){
			if(mark[tmp.first+dx[i]][tmp.second+dy[i]][0]==0&&a[tmp.first+dx[i]][tmp.second+dy[i]]!=-1)
			{	//未标记且能走就入队 
				q.push(pair<int,int>(tmp.first+dx[i],tmp.second+dy[i]));
				mark[tmp.first+dx[i]][tmp.second+dy[i]][0]=1;
				mark[tmp.first+dx[i]][tmp.second+dy[i]][1]=mark[tmp.first][tmp.second][1]+w;
				//更新权重 
			}
		}
	}
}


int main()
{
	iostream::sync_with_stdio(false);
	cin>>n>>m>>w;
	//围起边界
	for(int j=0;j<=m+1;++j)
	{
		a[0][j]=-1;
		a[n+1][j]=-1;
	}
	for(int i=0;i<=n+1;++i)
	{
		a[i][0]=-1;
		a[i][m+1]=-1;
	}
	
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			cin>>a[i][j];
		}
	}
	bfs(1,1,-1);
	for(int i=0;i<=n+1;++i)
	{
		for(int j=0;j<=m+1;++j)
		{
			mark[i][j][0]=0;
			mark[i][j][1]=0;
		}
	}
	bfs(1,1,0);
	bfs(n,m,1);
	if(ans==LONG_LONG_MAX&&(channel[0].weight==LONG_LONG_MAX||channel[1].weight==LONG_LONG_MAX))
	{
		cout<<-1<<endl;
	}
	else
	{
		if(channel[0].weight!=LONG_LONG_MAX&&channel[1].weight!=LONG_LONG_MAX&&(long long)(channel[0].weight+channel[1].weight)<ans)
			ans=channel[0].weight+channel[1].weight;
		cout<<ans<<endl;
	}
 	return 0;
}

