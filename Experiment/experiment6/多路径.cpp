#include<bits/stdc++.h>
using namespace std;
struct Node {
	set<int> behind;
	int pre;
	int mark;
	int ans;
	Node():pre(0),mark(0),ans(0){
	}
}node[400000+5];
class GraphTopo {
	private:
		int flag;
		int n,m;
		queue<int> tp;
		void sortExpand(){
			node[1].pre=0;
			node[1].ans=1;
			tp.push(1);//从1开始拓扑遍历 ,注意1的前驱,假设数量为0
			while(!tp.empty()) {
				int top=tp.front();
				tp.pop();
				for(auto it:node[top].behind) {
					if(it==1) {
						flag=1;
						continue;
					}//特殊情况如果从1开始走走回到了1，形成了环，路上所有点改为-1
					if(node[top].ans==2)
						node[it].ans=2; //该点有有限条路径，则后继也有有限条路径（非最终结果）
					node[it].mark+=1;
					if(node[it].mark==node[it].pre) {
						tp.push(it);  //前驱个数为0时以此为拓展
						if(node[it].mark==1&&node[it].ans!=2)
							node[it].ans=1;//该点前驱只有一个，且没有有限条路径的前驱（最终结果）
						else
							node[it].ans=2;//有有限条路径（最终结果）
					}
				}
			}
		}
		void sortCheck(){
			//处理完成后仅剩无法到达和无限路径。无限路径由mark不为0的点开始拓展，剩余都是无法到达的点
			for(int i=2; i<=n; ++i) { //循环检查每个点
				if(node[i].mark!=node[i].pre&&node[i].ans!=-1) { //排除有限路径的点和已结束标记的点
					tp.push(i);
					node[i].ans=-1;
					while(!tp.empty()) {
						int top=tp.front();
						tp.pop();
						for(auto it:node[top].behind) {
							if(it==1) {
								flag=1;
								continue;
							}
							if(node[it].mark!=node[it].pre&&node[it].ans!=-1) { //排除有限路径的点和已结束标记的点
								node[it].ans=-1;
								tp.push(it); //以此往后都是无限路径
							}
						}
					}
				}
			}
		}
	public:
		GraphTopo(){
		} 
		~GraphTopo(){
		}
		void initialTopo() {
			flag=0;
			cin>>n>>m;
			for(int i=1; i<=n; ++i) {
				node[i].behind.clear();
				node[i].pre=0;
				node[i].mark=0;
				node[i].ans=0;
			}
			for(int j=0; j<m; ++j) {
				int from,to;
				cin>>from>>to;
				node[from].behind.insert(to); //添加后继
				node[to].pre+=1; //前驱+1
			}
		}
		
		void sortTopo() {
			sortExpand();
			sortCheck();
		}
	
		void printTopo(){
			if(flag!=1){
				for(int i=1; i<=n; ++i) {
					cout<<node[i].ans<<' ';
				}
			}
			else{
				for(int i=1; i<=n; ++i) {
					if(node[i].ans!=0)
						cout<<-1<<' ';
				}
			}
			cout<<endl; 
		}
};
int main() {
	int t;
	cin>>t;
	GraphTopo graph;
	for(int i=0; i<t; ++i) {
		graph.initialTopo();
		graph.sortTopo();
		graph.printTopo();
	}
	return 0;
}

