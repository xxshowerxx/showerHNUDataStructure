#include<bits/stdc++.h>
using namespace std;
bool check(char c,double d){
	if(c=='A'||c=='B'||c=='C')
	{
		if(d<=600)
			return 1;
	}
	return 0;
}
double recursion(double *a,int i,double Q)
{
	if(i==0||Q<=0)
		return 0;
	else
	{
		if(Q<a[i])
			return recursion(a,i-1,Q);
		else
			return max(recursion(a,i-1,Q),recursion(a,i-1,Q-a[i])+a[i]);
	}
}
int main()
{
	double Q;
	int N;
	while(cin>>Q>>N,N!=0)
	{
		int t=1;
		double a[31]={0};
		for(int i=1;i<=N;++i)
		{
			int m;
			cin>>m;
			char tmpc,skip;
			double tmpd;
			double ans=0;
			int flag=1;
			for(int j=1;j<=m;++j)
			{
				cin>>tmpc>>skip>>tmpd;
				if(!check(tmpc,tmpd))
				{
					flag=0;
					break;
				}
				ans+=tmpd;
			}
			if(ans>1000)
				flag=0;
			if(flag==1)
			{
				a[t++]=ans;
			}
		}
		cout<<fixed<<setprecision(2)<<recursion(a,t-1,Q)<<endl;
	}
 	return 0;
}

