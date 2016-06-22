#include <iostream>
#include <set>

using namespace std;

int main ()
{
  set<int> myset;

  // set some initial values:
  myset.insert(3);
  myset.insert(6);
  myset.insert(9);
  myset.insert(9);
  myset.insert(9);
  myset.insert(12);

  for(int i = 0; i < 15; ++i){
    cout << i;
    if( myset.count(i) != 0 )
      cout << " is an element of myset." << endl;
    else
      cout << " is not an element of myset." << endl;
  }


  set<int>::iterator it;
  for( it = myset.begin(); it != myset.end(); ++it ) cout << *it << endl;
  
  
  return 0;
}
