#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> nodes(n, 0);
  int currentNode = 0;

  for (int i = 0; i < m; i++) {
    int action;
    cin >> action;
    if (action == 0) {
      currentNode = 0;
    } else if (action == 1) {
      currentNode++;
    } else if (action == 2) {
      nodes.insert(nodes.begin() + currentNode + 1, 0);
    } else if (action == 3) {
      int x;
      cin >> x;
      nodes[currentNode] += x;
    }
  }

  for (int i = 0; i < nodes.size(); i++) {
    cout << nodes[i] << " ";
  }
  return 0;
}
