#include<iostream>
using namespace std;
//QUEUE IMPLEMENTATION USING LINKLIST
template<class T>
struct node
{
  T data;
  node*next;
};

template<class T>
class queue
{
  node<T>*front,*rear;
public:
  queue():front(NULL),rear(NULL){}
  node<T>* create_node(T item)
  {
    node<T>*temp=new node<T>();
    if(temp!=NULL)//in case of no heap memory
    {
      temp->data=item;
      temp->next=NULL;
    }
    return temp;
  }
  int push(T item)
  {
    node<T>* temp=create_node(item);
    if(temp==NULL) return -1;
    if(front==NULL)
    {
      front=rear=temp;
      return 1;
    }
    rear->next=temp;
    rear=temp;
    return 1;
  }

  int pop()
  {
    if(front==NULL)//incase of empty queue
    {
      return -1;
    }
    //Deleting node from heap memory
    node<T>*temp=front;
    front=front->next;
    delete temp;
    temp=NULL;
    return 1;
  }
  T peek()
  {
    if(front!=NULL)// incase of empty queue
    {
      return front->data;
    }

  }
  int isempty()
  {
    if(front==NULL)return true;
    else return false;
  }
};

//STACK IMPLEMENTATION USING LINKLIST
template<class T>
class stack
{
  node<T>*top;
public:
  stack():top(NULL){}
  node<T>* create_node(T item)
  {
    node<T>*temp=new node<T>();
    if(temp!=NULL)
    {
      temp->data=item;
      temp->next=NULL;
    }
    return temp;
  }
  int push(T item)
  {
    node<T>*temp=create_node(item);
    if(temp==NULL) return -1;//in case of full heap memory
      if(top==NULL)
      {
        top=temp;
        return 1;
      }
      temp->next=top;
      top=temp;
      return 1;
  }
  int pop()
  {
    if(top==NULL)return -1;//in case of empty stack
    node<T>*temp=top;
    top=top->next;
    delete temp;
    temp=NULL;
    return 1;
  }
  int isempty()
  {
    if(top==NULL) return true;
    else return false;
  }
  T peek()
  {
    if(top!=NULL) return top->data;
  }
};
int main()
{
  int choice,x,option;
  stack<int> s;
  queue<int> q;
  do {

    cout<<"\nPress 1 for push operation STACK";
    cout<<"\nPress 2 for push operation in QUEUE";
    cout<<"\nPress 3 for pop operation in STACK";
    cout<<"\nPress 4 for pop operation in QUEUE";
    cout<<"\nPress 5 for peek from STACK";
    cout<<"\nPress 6 for peek from QUEUE";
    cout<<"\nPress 7 for checking empty STACK";
    cout<<"\nPress 8 for checking empty QUEUE";
    cout<<"\nEnter your choice\t";
    cin>>choice;
    switch(choice)
    {
      case 1:
      cout<<"Enter the value\t";
      cin>>x;
      if(s.push(x)==1)cout<<"Successfully inserted";
      else cout<<"Overflow";
      break;
      case 2:
      cout<<"Enter the value\t";
      cin>>x;
      if(q.push(x)==1)cout<<"Successfully inserted";
      else cout<<"Overflow";
      break;
      case 3:
      if(s.isempty()==0)
      {
        s.pop();
        cout<<"Successfully deleted";
      }
      else cout<<"Stack is empty";
      break;
      case 4:
      if(q.isempty()==0)
      {
        q.pop();
        cout<<"Successfully deleted";
      }
      else cout<<"Queue is empty";
      break;
      case 5:
      if(s.isempty()==0)
      {
        cout<<"Top element in stack "<<s.peek();
      }
      else cout<<"Stack is empty";
      break;
      case 6:
      if(q.isempty()==0)
      {
        cout<<"First element from queue is "<<q.peek();
      }
      else cout<<"Queue is empty";
      break;
      case 7:
      if(s.isempty()==1)cout<<"True";
      else cout<<"False";
      break;
      case 8:
      if(q.isempty()==1)cout<<"True";
      else cout<<"False";
      break;
      default:
      cout<<"Entered Wrong Choice";
      break;
    }
    cout<<"\nWant to continue (1/0)\t";
    cin>>option;

  } while(option==1);
  return 0;
}
