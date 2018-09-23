#include <iostream>
#include "smart_collection.h" // Using smart pointers (unique_ptr)
// or
//#include "collection.h"      // Using raw pointers
using namespace std;
int main(){
  Collection<int> c;
  c.add(3);
  c.add(4);
  c.add(6);
  c.add(9);
  c.add(2);
  c.add(10);
  cout << c << endl;

  Collection<int> b(c);
  cout << b << endl;

  for(int i : c){
    cout << i * 2 << endl;
  }
  return 0;
}