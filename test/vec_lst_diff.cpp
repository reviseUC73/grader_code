#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

int main () {

  vector<int> vec = { 10, 20, 30, 40 };
  auto it = find(vec.begin(), vec.end(), 1);
  cout<< *vec.end() ; // return 0
  cout<<"======="<<endl;

  list<int> vec1 = { 10, 20, 30, 40 };
  auto it1 = find(vec1.begin(), vec1.end(), 10);
  cout<< *vec1.end(); // return last postion

  
  // if (it != vec.end())
  //   cout << "Element found: " << *it;
  // else
  //   cout << "Element not found.";

  // return 0;
}