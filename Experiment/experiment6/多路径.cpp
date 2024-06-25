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
			tp.push(1);//��1��ʼ���˱��� ,ע��1��ǰ��,��������Ϊ0
			while(!tp.empty()) {
				int top=tp.front();
				tp.pop();
				for(auto it:node[top].behind) {
					if(it==1) {
						flag=1;
						continue;
					}//������������1��ʼ���߻ص���1���γ��˻���·�����е��Ϊ-1
					if(node[top].ans==2)
						node[it].ans=2; //�õ���������·��������Ҳ��������·���������ս����
					node[it].mark+=1;
					if(node[it].mark==node[it].pre) {
						tp.push(it);  //ǰ������Ϊ0ʱ�Դ�Ϊ��չ
						if(node[it].mark==1&&node[it].ans!=2)
							node[it].ans=1;//�õ�ǰ��ֻ��һ������û��������·����ǰ�������ս����
						else
							node[it].ans=2;//��������·�������ս����
					}
				}
			}
		}
		void sortCheck(){
			//������ɺ��ʣ�޷����������·��������·����mark��Ϊ0�ĵ㿪ʼ��չ��ʣ�඼���޷�����ĵ�
			for(int i=2; i<=n; ++i) { //ѭ�����ÿ����
				if(node[i].mark!=node[i].pre&&node[i].ans!=-1) { //�ų�����·���ĵ���ѽ�����ǵĵ�
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
							if(node[it].mark!=node[it].pre&&node[it].ans!=-1) { //�ų�����·���ĵ���ѽ�����ǵĵ�
								node[it].ans=-1;
								tp.push(it); //�Դ�����������·��
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
				node[from].behind.insert(to); //��Ӻ��
				node[to].pre+=1; //ǰ��+1
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

