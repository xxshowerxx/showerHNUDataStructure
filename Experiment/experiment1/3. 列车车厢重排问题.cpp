#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tmp,nowOut=1,k=0;
	stack<int> train;
	vector<queue<int>> H;
	while(cin>>tmp)
	{
		train.push(tmp);
	}
	while(!train.empty())
	{
		if(train.top()==nowOut)
		{
			nowOut++;
			train.pop();
		}
		else
		{
			int max=0,maxj=0,flag=0;
			for(int j=0;j<k;++j)
			{
				if(H[j].front()==nowOut)
				{
					H[j].pop();
					flag=1;
					nowOut++;
					break;
				}
				else if(H[j].back()<train.top()&&H[j].back()>max)
				{
					maxj=j;
					max=H[j].back();
				}
			}
			if(max!=0)
			{
				H[maxj].push(train.top());
				train.pop();
			}
			else if(!flag)
			{
				k++;
				queue<int> tmp;
				H.push_back(tmp);
				H[k-1].push(train.top());
				train.pop();
			}
		}
	}
	cout<<k+1<<endl;
 	return 0;
}

