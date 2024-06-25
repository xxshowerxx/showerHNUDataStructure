#include<bits/stdc++.h>
using namespace std;
int ans[2005];
int a[11];
void dp(int K,int M)
{
	for(int i=0;i<=M;i++)
		ans[i]=INT_MAX;
	ans[0]=0;
	for(int i=0;i<=M;++i)
	{
		for(int j=0;j<K;++j)
		{
			if(i-a[j]>=0&&ans[i-a[j]]!=INT_MAX)
				ans[i]=min(ans[i],ans[i-a[j]]+1);
		}
	}
}
int main() {
	int M;
	while(cin>>M,M!=0) {
		int K;
		cin>>K;
		for(int i=0; i<K; ++i) {
			cin>>a[i];
		}
		dp(K,M);
		if(ans[M]==INT_MAX)
			cout<<"Impossible"<<endl;
		else
			cout<<ans[M]<<endl;
	}
	return 0;
}

