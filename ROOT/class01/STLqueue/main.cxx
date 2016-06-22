// FIFO queue
#include <iostream>       // cout
#include <deque>          // deque
#include <list>           // list
#include <queue>          // queue

using namespace std;

int main ()
{
  deque<int> mydeck(3,100);        // deque with 3 elements
  list<int> mylist(2,200);         // list with 2 elements

  queue<int> first;                 // empty queue
  queue<int> second( mydeck );       // queue initialized to copy of deque

  queue<int,list<int> > third; // empty queue with list as underlying container
  queue<int,list<int> > fourth (mylist);

  cout << "size of first: " << first.size() << '\n';
  cout << "size of second: " << second.size() << '\n';
  cout << "size of third: " << third.size() << '\n';
  cout << "size of fourth: " << fourth.size() << '\n';

  return 0;
}


