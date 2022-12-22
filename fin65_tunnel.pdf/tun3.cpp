#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

// Struct to represent a tunnel
struct Tunnel {
  int A, B, H;
};

// Function to find the shortest path from S to T using BFS
int find_shortest_path(int N, int M, vector<Tunnel>& tunnels, int S, int T, int C) {
  // Initialize a graph with N nodes and no edges
  vector<vector<int>> graph(N);
  
  // Add the tunnels to the graph
  for (const Tunnel& tunnel : tunnels) {
    if (tunnel.H >= C) {
      graph[tunnel.A - 1].push_back(tunnel.B - 1);
      graph[tunnel.B - 1].push_back(tunnel.A - 1);
    }
  }
  
  // Initialize a queue for BFS and a set for keeping track of visited nodes
  queue<int> queue;
  vector<bool> visited(N);
  
  // Add the starting intersection to the queue and mark it as visited
  queue.push(S - 1);
  visited[S - 1] = true;
  
  // Initialize a distance array with all values set to infinity
  vector<int> distance(N, INF);
  
  // Set the distance to the starting intersection to 0
  distance[S - 1] = 0;
  
  // Loop while the queue is not empty
  while (!queue.empty()) {
    // Get the next intersection from the queue
    int current_intersection = queue.front();
    queue.pop();
    
    // Loop through the neighbors of the current intersection
    for (int neighbor : graph[current_intersection]) {
      // If the neighbor has not been visited yet, add it to the queue and mark it as visited
      if (!visited[neighbor]) {
        queue.push(neighbor);
        visited[neighbor] = true;
      }
      
      // Update the distance to the neighbor if it is shorter than the current distance
      if (distance[current_intersection] + 1 < distance[neighbor]) {
        distance[neighbor] = distance[current_intersection] + 1;
      }
    }
  }
  
  // Return the distance to the target intersection, or -1 if it is not reachable
  if (distance[T - 1] == INF) {
    return -1;
  } else {
    return distance[T - 1];
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  
  vector<Tunnel> tunnels(M);
  for (int i = 0; i < M; i++) {
    cin >> tunnels[i].A >> tunnels[i].B >> tunnels[i].H;
  }
  
  int S, T, C;
  cin >> S >> T >> C;
  
  cout << find_shortest_path(N, M, tunnels, S, T,C);
}