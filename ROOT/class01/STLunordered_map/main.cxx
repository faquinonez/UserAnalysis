#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

typedef unordered_map<string,string> stringmap;

stringmap merge( stringmap a, stringmap b ){
  stringmap temp(a); 
  temp.insert( b.begin(), b.end() ); 
  return temp;
}

int main ()
{
  stringmap first;                              // empty
  stringmap second( {{"apple","red"},{"lemon","yellow"}} );       // init list
  stringmap third( {{"orange","orange"},{"strawberry","red"}} );  // init list
  stringmap fourth( second );                    // copy
  stringmap fifth( merge( third, fourth ) );        // move
  stringmap sixth( fifth.begin(),fifth.end() );  // range

  cout << "sixth contains:";
  for(auto& x: sixth) cout << " " << x.first << ":" << x.second;
  cout << endl;

  stringmap::hasher fn = sixth.hash_function();
  cout << fn("apple") << endl; 


  return 0;
}
