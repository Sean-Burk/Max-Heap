#include "MaxHeap.h"
#include <iostream>
using namespace std;

void MaxHeap::print()
{
  for(int i=0;i<size;i++)
    cout<<arr[i]<<" ";
  cout<<endl;
}

MaxHeap::MaxHeap(int cap)
{
  arr = new int[cap];
  capacity=cap;
  size=0;
}

int MaxHeap::parent(int i)
{
  return (i-1)/2;
}

int MaxHeap::left(int i)
{
  return (i*2)+1;
}

int MaxHeap::right(int i)
{
  return (i*2)+2;
}

bool MaxHeap::isLeaf(int i)
{
  if(i>size/2)
    return true;
  return false;
}

void MaxHeap::siftup(int i)
{
  while(arr[i]>arr[parent(i)]&&i>0)
    {
      swap(i,parent(i));
      i=parent(i);
    }
  return;
}

void MaxHeap::siftdown(int i)
{
  int larger;
  while(!isLeaf(i))
    {
      int l=left(i);
      int r=right(i);
      if(arr[l]>arr[r])
	larger=l;
      else
	larger=r;
      if(arr[i]<arr[larger])
	{
	  swap(i,larger);
	  i=larger;
	}
      else 
	break;
    }
  return;
}

void MaxHeap::swap(int i,int x)
{
  int temp=arr[x];
  arr[x]=arr[i];
  arr[i]=temp;
}

int MaxHeap::getSize()
{
  return size;
}
int MaxHeap::getMax()
{
  return arr[0];
}
void MaxHeap::insert(int k)
{
  if(size>=capacity)
    throw Overflow();
  arr[size]=k;
  siftup(size);
  size++;
}
int MaxHeap::extractMax()
{
  if(size <= 0) throw Underflow();
  if(size == 1) return arr[--size];            
  int result = arr[0];    
  arr[0] = arr[--size];    
  siftdown(0);    
  return result;
}
int MaxHeap::removeAt(int i)
{
  if(size==0||size<=i)
    throw Underflow();
  size--;
  swap(i,size);
  if(arr[i]>arr[size])
    siftup(i);
  else
  siftdown(i);
  return arr[size];
}
void MaxHeap::heapify(int *array, int len)
{
  arr = array;    
  capacity = size = len;    
  for(int i = size/2-1; i>=0;i--)        
    siftdown(i);
}
