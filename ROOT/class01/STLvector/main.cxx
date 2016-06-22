#include <iostream>
#include <vector>

using namespace std;

int main ()
{
  vector<int> myvector;

  myvector.push_back(10);
  myvector.push_back(20);
  myvector.push_back(30);
  myvector.push_back(40);
  myvector.push_back(50);
  myvector.push_back(60);
  myvector.pop_back();

  cout << "myvector stores " << myvector.size() << " numbers." << endl;

  cout << endl;
  cout << "Loop 1: " << endl;
  vector<int>::iterator it;
  for( it = myvector.begin(); it != myvector.end(); ++it){
    cout << (*it) << endl;
  }  

  cout << endl;
  cout << "Loop 2: " << endl;
  unsigned int i;
  for( i=0; i < myvector.size(); i++){
    cout << myvector.at(i) << endl;
  }  

  return 0;
}


