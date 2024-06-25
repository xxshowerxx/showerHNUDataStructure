#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(a+1!=c)
			cout<<"-1"<<endl;
		else{
			int above;
			if(a!=0&&b!=0)
			{
				int right=pow(2,ceil(log2(a+1)))-1-a;
				if(right>=b)
					above=ceil(log2(a+1));
				else
				{
					b-=right;
					int left=pow(2,ceil(log2(a+1))-1)-right;
					above=ceil(log2(a+1))+ceil(1.0*b/(2*left+right));
				}
			}
			else if(a==0&&b==0)
				above=0;
			else if(b==0)
				above=ceil(log2(a+1));
			else if(a==0)
				above=b; 
			cout<<above<<endl;
		}
	}
 	return 0;
}

