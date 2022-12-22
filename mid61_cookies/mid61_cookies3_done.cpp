#include <iostream>
#include <vector>

using namespace std;

int main() {
  // Read the number of operations
  int T;
  cin >> T;

  // Initialize a vector to store the cookies
  vector<int> cookies;

  // Perform the operations
  while (T--) {
    // Read the operation type and the index of the cookie
    int L, k;
    cin >> L >> k;

    // If the operation is an insert, read the number of the cookie and add it to the vector
    if (L == 1) {
      int x;
      cin >> x;
      // If the index of the cookie is larger than the current size of the vector, add the cookie to the end of the vector
      if (k >= cookies.size()) {
        cookies.push_back(x);
      }
      // Otherwise, insert the cookie at the specified index
      else {
        cookies.insert(cookies.begin() + k, x);
      }
    }
    // If the operation is an eat, remove the cookie at the specified index if it exists
    else {
      // Adjust the index to account for the fact that the first cookie has index 1, not 0
      k--;
      if (k < cookies.size()) {
        cookies.erase(cookies.begin() + k);
      }
    }
  }

  // Print the final row of cookies
  for (int cookie : cookies) {
    cout << cookie << endl;
  }

  return 0;
}
