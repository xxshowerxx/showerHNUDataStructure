#include<bits/stdc++.h>
using namespace std;

// ����Trie���Ľڵ�ṹ
struct Node {
    char alpha=0; // �ڵ�洢���ַ�
    bool isEnd=false; // �Ƿ�Ϊ���ʽ�β
    int time=0; // ���ʳ��ֵĴ���
    map<char,Node*> next; // �ӽڵ�
    Node(){}
	Node(char c):alpha(c){}
};

// �Զ���ȽϺ������������ȶ���
class compare{
    public:
    bool operator() (const pair<int,string>&x,const pair<int,string>&y){
        if(x.first==y.first)
            return x.second>y.second;
        else return x.first<y.first;
    }
};

// Trie����
class Trie {
    private:
        Node *root; // ���ڵ�
        priority_queue<pair<int,string>,vector<pair<int,string>>,compare> frequency; // ���ȶ��У����ڴ洢���ʼ�����ִ���

        // �ݹ����Trie���������ʼ�����ִ����������ȶ���
        void traverseHelp(Node* curr,string path) {
            if(curr!=root) {
                path+=(char)curr->alpha;
                if(curr->isEnd==true) {
                    pair<int,string> tmp(curr->time,path);
                    frequency.push(tmp);
                }
            }
            if(!curr->next.empty()) {
                for(auto it:curr->next) {
                    traverseHelp(it.second,path);
                }
            }
            return;
        }

        // �ݹ�ɾ��Trie�������нڵ�
        void deleteTrie(Node*curr){
            if(curr==NULL)
                return;
            for(auto it:curr->next)
                deleteTrie(it.second);
            delete curr;
            return;
        }

    public:
        Trie() {
            root=new Node();
        }
        ~Trie(){
            deleteTrie(root);
        } 

        // ���浥�ʵ�Trie����
        void saveWord(string s) {
            Node *curr=root;
            for(char c:s) {
                if(curr->next.find(c)==curr->next.end())
                {
                    curr->next[c]=new Node(c);
                }
                curr=curr->next[c];
            }
            curr->isEnd=true;
            curr->time+=1;
        }

        // ����Trie���������ʼ�����ִ����������ȶ���
        void traverse() {
            traverseHelp(root,"");
        }

        // ��ӡ���ȶ����е�ǰ100�����ʼ�����ִ���
        void printHeap() {
            for(int i=0; i<100; i++) {
                if(frequency.empty())
                    break;
                pair<int,string> tmp=frequency.top();
                frequency.pop();
                cout<<tmp.second<<" "<<tmp.first<<endl;
            }
        }
};

// �ж��ַ��Ƿ�Ϊ��ĸ
bool isChar(char c) {
    if((c>='A'&&c<='Z')||(c>='a'&&c<='z')) {
        return 1;
    } else {
        return 0;
    }
}

// ����д��ĸת��ΪСд��ĸ
char convertChar(char c) {
    if(c>='A'&&c<='Z')
        return char(c-'A'+'a');
    else return c;
}

int main() {
    ifstream readFile("in.txt",ios::in);
    Trie myTrie;
    while(!readFile.eof()) {
        string tmp,word="";
        readFile>>tmp;
        for(char c:tmp) {
            if(isChar(c)) {
                word+=convertChar(c);
            } else { 
                myTrie.saveWord(word); // �����ʱ��浽Trie����
                word=""; // ��յ����ַ���
            }
        }
        if(word!="") 
            myTrie.saveWord(word); // ��ʣ�൥�ʱ��浽Trie����
    }
    myTrie.traverse(); // ����Trie���������ʼ�����ִ����������ȶ���
    myTrie.printHeap(); // ��ӡ���ȶ����е�ǰ100�����ʼ�����ִ���
    return 0;
}


