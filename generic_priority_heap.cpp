#include <iostream>
#include <vector>
using namespace std;

/*
PriorityHeap class takes two template arguements
first template arguement: data-type of key
second template arguement: a functor(function object) 
for key comparison(Default: less<key>)
*/
template <class key,class Compare=less<key>>
class PriorityHeap
{
    vector<key> heap;
    int _size;
    Compare compare;
    void upHeapify(int child);
    void downHeapify(int parent);
    public:
        PriorityHeap()
        {
          _size = 0;
        }
        int size();
        void add(key element);
        key extract();
        void erase();
};

//size() to get the current size of heap
template <class key,class Compare>
int PriorityHeap<key,Compare>::size()
{
  return heap.size();
}

//erase() to clear the heap
template <class key,class Compare>
void PriorityHeap<key,Compare>::erase()
{
  _size=0;
  heap.resize(_size);
}

//extract() to extract the topmost element in the heap
template <class key,class Compare>
key PriorityHeap<key,Compare>::extract()
{
  key answer = heap[0];
  heap[0] = heap[_size-1];
  _size--;
  heap.resize(_size);
  downHeapify(0);
  return answer;
}

//add() to add an element to the heap
template <class key,class Compare>
void PriorityHeap<key,Compare>::add(key element)
{
    heap.push_back(element);
    _size = heap.size();
    upHeapify(_size-1);
}

//downHeapify() rearranges the heap top-to-bottom whenever an element is extracted
template <class key,class Compare>
void PriorityHeap<key,Compare>::downHeapify(int parent)
{
  int minChild,
  child1 = 2*parent+1, 
  child2 = 2*parent+2;
  if(child2<_size)
  {
    if(compare(heap[child1],heap[child2]))
      minChild = child1;
    else
      minChild = child2; 
  }
  else if(child1<_size)
    minChild = child1;
  else  return;
  if(compare(heap[minChild],heap[parent]))
  {
    swap(heap[minChild],heap[parent]);
    downHeapify(minChild);
  }
}

//upHeapify rearranges the heap bottom-to-top whenever a new element is added
template <class key,class Compare>
void PriorityHeap<key,Compare>::upHeapify(int child)
{
    
    int parent = (child-1)/2;
    if(compare(heap[child],heap[parent]))
    {
        swap(heap[child],heap[parent]);
        if(parent!=0)
            upHeapify(parent);
    }
}


//Functor for illustrating example
template <class T>
class cmp{
  public:
  bool operator() (T &a,T &b) {return a>b;}
};

int main()
{
    //Example how to create a heap of strings
    PriorityHeap<string> heap;
    heap.add("Vivek");
    heap.add("Rohan");
    heap.add("Shubham");
    heap.add("Manish");
    heap.add("Nimish");
    heap.add("Poply");
    while(heap.size())
    {
      cout<<heap.extract()<<" ";
    }

    cout<<endl;
    
    //Example how to use PriorityHeap with a functor
    PriorityHeap<int,cmp<int>> heap2;
    heap2.add(4);
    heap2.add(7);
    heap2.add(25);
    heap2.add(8);
    heap2.add(2);
    heap2.add(13);
    while(heap2.size())
    {
      cout<<heap2.extract()<<" ";
    }

    return 0;
}
