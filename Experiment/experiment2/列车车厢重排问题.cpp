#include<bits/stdc++.h>
using namespace std;
template<typename E>class Link{
	public:
	E element;
	Link<E>* next;
	Link():next(NULL){
	}
	Link(const E&e,Link<E>*n):element(e),next(n){}
};

template<typename E>class QueueADT{
	private:
		void operator =(const QueueADT&) {}
	public:
		QueueADT() {}
		virtual ~QueueADT() {}
		virtual void clear() = 0;
		virtual void init() =0;
		virtual void enqueue(const E&it) = 0;
		virtual E dequeue() = 0;
		virtual const E& frontValue() const = 0;
		virtual const E& backValue() const = 0;
		virtual bool empty() const = 0;
	
};

template<typename E>class Queue:public QueueADT<E>{
	private:
		Link<E>* front;
		Link<E>* rear;
		int size;
	public:
		Queue(){
			init();
		}
		Queue(const Queue<E>&another){
			init();
		}
		Queue(Queue<E>&another){
			init();
			while(!another.empty())
				this->enqueue(another.dequeue());
		}
		~Queue(){
			clear();
		}
		void init(){
			front=rear=new Link<E>;
			size=0;
		}
		void clear(){
			Link<E>*p=front->next;
			if(p!=NULL)
			{
				delete front;
				front=p;
				p=p->next;
			}
			rear=front;
			size=0;
		}
		void enqueue(const E&it)
		{
			rear->next=new Link<E>(it,NULL);
			rear=rear->next;
			size++;
		}
		E dequeue(){
			E ans=front->next->element;
			Link<E> *ltemp=front->next;
			front->next=front->next->next;
			if(ltemp==rear) rear=front;
			delete ltemp;
			size--;
			return ans;
		}
		const E&frontValue()const
		{
			return front->next->element;
		}
		const E&backValue()const
		{
			return rear->element;
		}
		bool empty()const
		{
			return size==0;
		}
};

template<typename E>class StackADT
{
	private:
	void operator =(const StackADT&) {}
	StackADT(const StackADT&) {}
	public:
		StackADT() {}
		virtual ~StackADT() {}
		virtual void init() = 0;
		virtual void clear() = 0;
		virtual void push(const E& it) = 0;
		virtual E pop() = 0;
		virtual const E& topValue() const = 0;
		virtual bool empty() const = 0;
};

template<typename E>class Stack:public StackADT<E>{
	private:
	Link<E>*top;
	int size;
	public:
		Stack(){
			init();
		}
		~Stack(){
			clear();
		}
		void init(){
			top=NULL;
			size=0;
		}
		void clear(){
			while(top!=NULL)
			{
				Link<E>*temp=top;
				top=top->next;
				delete temp;
			}
			size=0;
		}
		void push(const E&it)
		{
			top=new Link<E>(it,top);
			size++;
		}
		E pop(){
			E it = top->element;
    		Link<E>* ltemp = top->next;
    		delete top;
    		top = ltemp;
    		size--;
    		return it;
		}
		const E& topValue() const { 
    	return top->element;
  		}
  		bool empty()const{
  			return size==0;
		  }
};
int main()
{
	int tmp,nowOut=1,k=0;
	Stack<int> train;
	vector<Queue<int>>H(100);
	while(cin>>tmp)
	{
		train.push(tmp);
	}
	while(!train.empty())
	{
		if(train.topValue()==nowOut)
		{
			nowOut++;
			train.pop();
		}
		else
		{
			int max=0,maxj=0,flag=0;
			for(int j=0;j<k;++j)
			{
				if(!H[j].empty()&&H[j].frontValue()==nowOut)
				{
					H[j].dequeue();
					flag=1;
					nowOut++;
					break;
				}
				else if(H[j].empty())
				{
					maxj=j;
					max=1;
					break;
				}
				else if(H[j].backValue()<train.topValue()&&H[j].backValue()>max)
				{
					maxj=j;
					max=H[j].backValue();
				}
			}
			if(max!=0)
			{
				H[maxj].enqueue(train.pop());
			}
			else if(!flag)
			{
				k++;
				Queue<int> *q=new Queue<int>;
				H.push_back(*q);
				H[k-1].enqueue(train.pop());
			}
		}
	}
	cout<<k+1<<endl;
 	return 0;
}

