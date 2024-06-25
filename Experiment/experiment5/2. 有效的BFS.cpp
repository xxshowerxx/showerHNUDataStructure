#include<bits/stdc++.h>
using namespace std;
vector<set<int>> ne(2*pow(10,5)+5);
queue<int> a;
queue<int> b;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n-1;++i)
	{
		int x,y;
		cin>>x>>y;
		ne[x].insert(y);
		ne[y].insert(x);
	}
	for(int i=1;i<=n;++i)
	{
		int tmp;
		cin>>tmp;
		a.push(tmp);
	}
	int flag=1;
	int parent=0,child=0;
	parent=a.front();
	a.pop();
	while(!a.empty())
	{
		while(ne[parent].empty())
		{
			if(b.empty())
			{
				cout<<"No"<<endl;
				return 0;
			}
			parent=b.front();
			b.pop();
		}
		child=a.front();
		a.pop();
		if(ne[parent].find(child)!=ne[parent].end())
		{
			ne[parent].erase(child);
			ne[child].erase(parent);
			b.push(child);
		}
		else
		{
			flag=0;
			break;
		}
	}
	if(flag)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
 	return 0;
}

