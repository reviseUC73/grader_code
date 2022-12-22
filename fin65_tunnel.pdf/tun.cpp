#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

struct Tunnel {
  int start;
  int end;
  int height;
};

vector<vector<Tunnel>> createAdjacencyList(int N, const vector<Tunnel>& tunnels) {
  // create an empty adjacency list
  vector<vector<Tunnel>> adjacencyList(N);

  // add each tunnel to the adjacency list
  for (const Tunnel& tunnel : tunnels) {
    adjacencyList[tunnel.start - 1].push_back(tunnel);
    adjacencyList[tunnel.end - 1].push_back(tunnel);
  }

  return adjacencyList;
}

int findLowestFee(int N, int M, const vector<Tunnel>& tunnels, int S, int T, int C) {
  // create an adjacency list to represent the graph
  vector<vector<Tunnel>> adjacencyList = createAdjacencyList(N, tunnels);

  // initialize a queue for the BFS
  queue<int> queue;

  // add the starting intersection to the queue
  queue.push(S);

  // initialize a set to keep track of visited intersections
  unordered_set<int> visited;

  // initialize the cost and number of tunnels visited to 0
  int cost = 0;
  int numTunnels = 0;

  // perform the BFS
  while (!queue.empty()) {
    // get the next intersection from the queue
    int intersection = queue.front();
    queue.pop();

    // mark the intersection as visited
    visited.insert(intersection);

    // check if the intersection is the destination
    if (intersection == T) {
      return cost;
    }

    // add the connected tunnels to the queue, as long as they are tall enough for the car
    for (const Tunnel& tunnel : adjacencyList[intersection - 1]) {
      int end = (tunnel.start == intersection) ? tunnel.end : tunnel.start;
      if (tunnel.height >= C && visited.count(end) == 0) {
        queue.push(end);
        numTunnels += 1;
        cost += 1;
      }
    }
  }

  // if the destination is not reached, it is not possible to reach it with the given car height
  return -1;
}

int main() {
  // example usage
  vector<Tunnel> tunnels = {
    {1, 2, 15},
    {3, 2, 3},
    {4, 2, 18},
    {3, 4, 30},
    {3, 5, 13},
    {4, 1, 8},
    {4, 5, 7}
  };
  cout << findLowestFee(5, 7, tunnels, 1, 5, 7) << endl;  // should print 2
  cout << findLowestFee(5, 7, tunnels, 1, 5, 10) << endl;  // should print 4
//   cout << findLowestFee(5, 7, tunnels, 1, 5)<< endl; // should
}