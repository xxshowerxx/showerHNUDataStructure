#include<bits/stdc++.h>
using namespace std;
int main() {
	int T;
	cin>>T;
	while(T--) {
		string s;
		cin>>s;
		int n=s.length(),ans=0;
		int maxl=0;
		for(int i=0; i<2*n-1; i++) {
			int l=i/2,r=(i+1)/2;
			while(l>=0&&r<n&&s[l]==s[r])
			{
				l--;
				r++;
			}
			if(r-l-1>ans)
			{
				ans=r-l-1;
				maxl=l+1;
			}
		}
		cout<<maxl<<" "<<ans<<endl;
	}
return 0;
}

