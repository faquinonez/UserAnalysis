#include <iostream>
#include <map>

using namespace std;

int main ()
{
  map<char,int> mymap;

  mymap['b'] = 100;
  mymap['a'] = 200;
  mymap['c'] = 300;

  // show content:
  map<char,int>::iterator it;
  for( it = mymap.begin(); it != mymap.end(); ++it ){
    cout << it->first << " => " << it->second << endl;
  }

  return 0;
}

