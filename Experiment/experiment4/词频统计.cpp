#include<bits/stdc++.h>
using namespace std;

// 定义Trie树的节点结构
struct Node {
    char alpha=0; // 节点存储的字符
    bool isEnd=false; // 是否为单词结尾
    int time=0; // 单词出现的次数
    map<char,Node*> next; // 子节点
    Node(){}
	Node(char c):alpha(c){}
};

// 自定义比较函数，用于优先队列
class compare{
    public:
    bool operator() (const pair<int,string>&x,const pair<int,string>&y){
        if(x.first==y.first)
            return x.second>y.second;
        else return x.first<y.first;
    }
};

// Trie树类
class Trie {
    private:
        Node *root; // 根节点
        priority_queue<pair<int,string>,vector<pair<int,string>>,compare> frequency; // 优先队列，用于存储单词及其出现次数

        // 递归遍历Trie树，将单词及其出现次数存入优先队列
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

        // 递归删除Trie树的所有节点
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

        // 保存单词到Trie树中
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

        // 遍历Trie树，将单词及其出现次数存入优先队列
        void traverse() {
            traverseHelp(root,"");
        }

        // 打印优先队列中的前100个单词及其出现次数
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

// 判断字符是否为字母
bool isChar(char c) {
    if((c>='A'&&c<='Z')||(c>='a'&&c<='z')) {
        return 1;
    } else {
        return 0;
    }
}

// 将大写字母转换为小写字母
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
                myTrie.saveWord(word); // 将单词保存到Trie树中
                word=""; // 清空单词字符串
            }
        }
        if(word!="") 
            myTrie.saveWord(word); // 将剩余单词保存到Trie树中
    }
    myTrie.traverse(); // 遍历Trie树，将单词及其出现次数存入优先队列
    myTrie.printHeap(); // 打印优先队列中的前100个单词及其出现次数
    return 0;
}


