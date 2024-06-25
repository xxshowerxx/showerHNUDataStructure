#include<bits/stdc++.h>
using namespace std;
string pre,in,post;
int preOrderIndex;
int getMiddle(){
	for(int i=0;i<(int)in.length();++i)
	{
		if(pre[preOrderIndex]==in[i])
			return i;
	}
	return 0;
}
void postOrder(int middle,int left,int right){
	if(left==middle&&right==middle)
	{
		post+=in[middle];
		return;
	}
	if(left!=middle)
	{
		++preOrderIndex;
		postOrder(getMiddle(),left,middle-1);
	}
	if(right!=middle)
	{
		++preOrderIndex;
		postOrder(getMiddle(),middle+1,right);
	}
	post+=in[middle];
	return;
}
int main()
{
	int n;
	while(cin>>n,n){
		cin>>pre>>in;
		post="";
		preOrderIndex=0;
		int middle=getMiddle();
		postOrder(middle,0,in.size()-1);
		cout<<post<<endl;
	}
 	return 0;
}

