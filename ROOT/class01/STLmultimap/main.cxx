#include <iostream>
#include <map>

using namespace std;

int main ()
{
  multimap<char,int> mymultimap;

  mymultimap.insert( pair<char,int>('a',10) );
  // one key may have multiple values "multimap"
  mymultimap.insert( pair<char,int>('b',20) );
  mymultimap.insert( pair<char,int>('b',150) );

  // show content:
  multimap<char,int>::iterator it;
  for( it = mymultimap.begin(); it != mymultimap.end(); ++it )
    cout << (*it).first << " => " << (*it).second << endl;

  return 0;
}

