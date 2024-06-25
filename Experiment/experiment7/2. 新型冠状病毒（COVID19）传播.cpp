#include<bits/stdc++.h>
using namespace std;
int S[1000005],V[1000005];
int main()
{
	int N,K;
	cin>>N>>K;
	int cnt=0;
	for(int i=1;i<=N;++i)
	{
		cin>>S[i];
	}
	for(int i=1;i<=N;++i)
	{
		cin>>V[i];
	}
	int Vmax=V[K],Vmin=V[K];
	for(int i=1;i<=N;++i)
	{
		if(i==K)
			continue;
		if(S[i]<S[K]&&V[i]>Vmax)
		{
			Vmax=V[i];
		}
		else if(S[i]>S[K]&&V[i]<Vmin)
		{
			Vmin=V[i];
		}
	}
	for(int i=1;i<=N;++i)
	{
		if(i==K)
			continue;
		if(S[i]<S[K]&&V[i]<=Vmin)
		{
			cnt++;
		}
		else if(S[i]>S[K]&&V[i]>=Vmax)
		{
			cnt++;
		}
	}
	cout<<N-cnt<<endl;
 	return 0;
}

