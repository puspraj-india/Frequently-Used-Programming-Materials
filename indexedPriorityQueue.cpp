#include<bits/stdc++.h>
using namespace std;
//Max heap, maximum value has highest priority
//Global Declarations
int size;
unordered_map<char,int>ci;
unordered_map<int,char>ic;
vector<int> position_map,inverse_position_map,values;


//Function to heapify
void heapify(int index)
{
  int largest=index;
  int left=index*2+1;
  int right=index*2+2;
  if(left<size&&values[inverse_position_map[left]]>values[inverse_position_map[largest]])
  {
    largest=left;
  }
  if(right<size &&values[inverse_position_map[right]]>values[inverse_position_map[largest]])
  {
    largest=right;
  }
  if(largest!=index)
  {
    int temp=inverse_position_map[index];
    inverse_position_map[index]=inverse_position_map[largest];
    inverse_position_map[largest]=temp;
    position_map[inverse_position_map[index]]=index;
    position_map[inverse_position_map[largest]]=largest;
    heapify(largest);
  }
}
//function to insert certain element
void bubbleup(int index)
{
  int parent=(index-1)/2;
  int temp;
  int mi=inverse_position_map[index];
  int mp=inverse_position_map[parent];
  while(values[mi]>values[mp])
  {
    temp=inverse_position_map[parent];
    inverse_position_map[parent]=inverse_position_map[index];
    inverse_position_map[index]=temp;
    position_map[inverse_position_map[index]]=index;
    position_map[inverse_position_map[parent]]=parent;
    index=parent;
    parent=(index-1)/2;
    mi=inverse_position_map[index];
    mp=inverse_position_map[parent];
  }
}
void insert()
{
  int s=size;
  char c;
  int x;
  cout<<"Enter the key";
  cin>>c;
  ic[c]=s;
  ci[s]=c;
  cout<<"Enter the value";
  cin>>x;
  inverse_position_map.push_back(s);
  position_map.push_back(s);
  values.push_back(x);
  bubbleup(s);
  size+=1;
}

//function to remove element with specified position(index) in array
//ki refers to key index
void remove(int ki)
{
  int index=position_map[ki];//index refers to heap index
  // position_map[inverse_position_map[index]]=size-1;
  // position_map[inverse_position_map[size-1]]=index;
  int temp=inverse_position_map[index];
  inverse_position_map[index]=inverse_position_map[size-1];
  inverse_position_map[size-1]=temp;
  position_map[inverse_position_map[index]]=index;
  position_map[ki]=-1;
  size--;
  bubbleup(index);
  heapify(index);
  values[ki]=-1;
}
int main()
{
  int x;
  char c;
  cout<<"\nEnter the number of keys\t";
  cin>>size;
  for(int i=0;i<size;i++)
  {
    cin>>c;
    ci[c]=i;
    ic[i]=c;
  }
  //the values array is created for maintaining the values associated with each key.
  //vector<int> values(n);

  cout<<"Enter the values for each key\t";
  for(int i=0;i<size;i++)
  {
    //cin>>values[i];
    cin>>x;
    values.push_back(x);
  }
  //Now we are going to create some new relationships so that we can know the index of the value in the heap, basically how anyone know what's it's index in the heap
  //position_map, this array tells us the index in the heap of a particular key
  //Actually first creating Inverse_position_map will be far better than creating position map, since position map can be derived from inverse_position_map, by the way it
  //vector<int> inverse_position_map;
  for(int i=0;i<size;i++)
  {
    inverse_position_map.push_back(i);
    position_map.push_back(i);
  }

  for(int start=size/2-1;start>=0;--start)
  {
    heapify(start);
  }
  for(int i=0;i<size;i++)
  cout<<i<<"\t";
  cout<<endl;
  for(int i=0;i<size;i++)
  {
    cout<<inverse_position_map[i]<<"\t";
  }
  cout<<endl;
  for(int i=0;i<size;i++)
  cout<<position_map[i]<<"\t";
  cout<<endl;
  for(int i=0;i<size+1;i++)
  {
    cout<<i<<"\t";
  }
  cout<<endl;
  for(int i=0;i<size+1;++i)
  {
    cout<<inverse_position_map[i]<<"\t";
  }
  cout<<endl;
  for(int i=0;i<size+1;++i)
  {
    cout<<position_map[i]<<"\t";
  }
  return 0;
}
