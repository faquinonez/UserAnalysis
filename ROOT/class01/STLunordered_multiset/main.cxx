#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

template<class T>
T cmerge (T a, T b){ 
  T t(a); 
  t.insert( b.begin(), b.end() ); 
 return t; 
}

int main ()
{
  unordered_multiset<string> first;                                // empty
  unordered_multiset<string> second( {"red","green","blue"} );    // init list
  unordered_multiset<string> third( {"red","yellow","blue"} );    // init list
  unordered_multiset<string> fourth( second );                    // copy
  unordered_multiset<string> fifth( cmerge(third,fourth) );       // move
  unordered_multiset<string> sixth( fifth.begin(), fifth.end() ); // range

  cout << "sixth contains:";
  for (const string& x: sixth) cout << " " << x;
  cout << endl;

  return 0;
}


