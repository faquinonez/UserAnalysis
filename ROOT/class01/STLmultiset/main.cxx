#include <iostream>
#include <set>

using namespace std;

int main()
{
  multiset<int> mymultiset;
  mymultiset.insert(10);
  mymultiset.insert(73);
  mymultiset.insert(12);
  mymultiset.insert(22);
  mymultiset.insert(73);
  mymultiset.insert(73);
  mymultiset.insert(12);

  cout << "73 appears " << mymultiset.count(73) << " times in mymultiset." << endl;

  multiset<int>::iterator it;
  for( it = mymultiset.begin(); it != mymultiset.end(); ++it){
    cout << *it << endl;
  }

  return 0;
}


