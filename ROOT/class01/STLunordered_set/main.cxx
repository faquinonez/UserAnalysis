#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

template<class T>
T cmerge(T a, T b){ 
  T t(a); 
  t.insert(b.begin(),b.end()); 
  return t; 
}

typedef unordered_set<string> stringset;

int main ()
{
  unordered_set<string> first;                                // empty
  unordered_set<string> second( {"red","green","blue"} );    // init list
  unordered_set<string> third( {"orange","pink","yellow"} ); // init list
  unordered_set<string> fourth( second );                    // copy
  unordered_set<string> fifth( cmerge(third,fourth) );       // move
  unordered_set<string> sixth( fifth.begin(), fifth.end() ); // range

  cout << "sixth contains:";
  for( const string& x: sixth) cout << " " << x;
  cout << std::endl;


  stringset myset;
  stringset::hasher fn = myset.hash_function();
  cout << "that: " << fn("that") << endl;
  cout << "than: " << fn("than") << endl;

  /* Returns the bucket number where the element with value k is located.

  A bucket is a slot in the container's internal hash table to which elements are assigned 
  based on their hash value. Buckets are numbered from 0 to (bucket_count-1).

  Individual elements in a bucket can be accessed by means of the range iterators returned 
  by unordered_set::begin and unordered_set::end.
  */
  unordered_set<string> myset2 = {"water","sand","ice","foam"};
  cout << "myset2 bucket count = " << myset2.bucket_count() << endl;
  for(const string& x: myset2) {
    cout << x << " is in bucket #" << myset2.bucket(x) << endl;
  }

  unordered_set<string> myset3 =
  {"Mercury","Venus","Earth","Mars","Jupiter","Saturn","Uranus","Neptune"};

  cout << "myset3 contains:";
  for( auto it = myset3.begin(); it != myset3.end(); ++it ) cout << " " << *it;
  cout << endl;

  cout << "myset3's buckets contain: " << endl;
  for( unsigned i = 0; i < myset3.bucket_count(); ++i ) {
    cout << "bucket #" << i << " contains:";
    for( auto local_it = myset3.begin(i); local_it != myset3.end(i); ++local_it ) cout << " " << *local_it;
    cout << endl;
  }



  return 0;
}


