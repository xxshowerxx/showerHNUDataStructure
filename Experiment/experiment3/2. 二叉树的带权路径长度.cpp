#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n=0;
	while(cin>>n,n){
		priority_queue<int,vector<int>,greater<int>> huffman;
		int tmp,ans=0;
		for(int i=0;i<n;++i){
			cin>>tmp;
			huffman.push(tmp);
		}
		while(huffman.size()!=1){
			tmp=huffman.top();
			huffman.pop();
			tmp+=huffman.top();
			huffman.pop();
			huffman.push(tmp);
			ans+=tmp;
		}
		cout<<ans<<endl;
	}
	return 0;
}

