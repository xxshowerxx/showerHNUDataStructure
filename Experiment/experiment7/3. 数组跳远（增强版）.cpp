#include<bits/stdc++.h>
using namespace std;
long long a[2*100000+5];
long long s[2*100000+5];
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;++i)
	{
		int n;
		cin>>n;
		for(int j=1;j<=n;++j)
		{
			cin>>a[j];
		}
		for(int k=n;k>=1;--k)
		{
			if(a[k]+k>n)
				s[k]=a[k];
			else
			{
				s[k]=a[k]+s[a[k]+k];
			}
		}
		long long ans=0;
		for(int i=1;i<=n;++i)
		{
			if(ans<s[i])
				ans=s[i];
		}
		cout<<ans<<endl;
	}
 	return 0;
}

