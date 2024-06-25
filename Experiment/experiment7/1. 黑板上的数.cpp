#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long k,s=0;
	int cnt=0;
	string n;
	cin>>k;
	cin>>n;
	int a[10]={0};
	for(int i=0;i<(int)n.length();i++)
	{
		a[n[i]-'0']+=1;
		s+=n[i]-'0';
	}
	for(int i=0;i<=8;++i)
	{
		if(s>=k)
			break;
		if(s+a[i]*(9-i)>=k)
		{
			int t=(k-s)/(9-i);
			if((k-s)%(9-i)!=0)
				t+=1;
			s=k;
			cnt+=t;
		}
		else
		{
			s+=a[i]*(9-i);
			cnt+=a[i];
		}
	}
	cout<<cnt<<endl;
 	return 0;
}

