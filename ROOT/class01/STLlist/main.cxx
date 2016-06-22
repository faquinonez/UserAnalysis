#include <iostream>
#include <list>

using namespace std;

int main ()
{
  list<int> mylist;

  mylist.push_back(50);
  mylist.push_back(100);
  mylist.push_back(200);
  mylist.push_back(300);
  mylist.push_back(340);
  mylist.pop_back();
  mylist.pop_front();
  mylist.push_front(0);

  list<int>::iterator it;
  for( it = mylist.begin(); it != mylist.end(); ++it ){
    cout << *it << endl;
  }


  return 0;
}
