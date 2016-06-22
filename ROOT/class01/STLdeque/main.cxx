// Double ended queues
#include <iostream>
#include <deque>

using namespace std;

int main ()
{
  unsigned int i;

  // constructors used in the same order as described above:
  deque<int> first;                                // empty deque of ints
  deque<int> second(4,100);                       // four ints with value 100
  deque<int> third(second.begin(),second.end());  // iterating through second
  deque<int> fourth(third);                       // a copy of third

  // the iterator constructor can be used to copy arrays:
  int myints[] = {16,2,77,29};
  deque<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

  cout << "The contents of fifth are:";
  for (deque<int>::iterator it = fifth.begin(); it!=fifth.end(); ++it)
    cout << ' ' << *it;

  cout << '\n';

  return 0;
}

