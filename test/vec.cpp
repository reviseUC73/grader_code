// #include <iostream>
// #include <stdio.h>
// #include <vector>

// using namespace std;

// // // cell structure denoted as point
// // struct point
// // {
// //     int x, y;
// // };
// // int main()
// // {
// //     // arr stores sequence of points
// //     // that are to be visited
// //     point arr[] = {{4, 6}, {1, 2}, {4, 5}, {10, 12}};

// //     // int n = sizeof(arr) / sizeof(arr[0]);
// //     // cout << coverPoints(arr, n);
// //     cout<< arr[1].x;
// // }
// // #include <iostream>

// // int main() {
// //   // read N and L from input
// //   int N, L, fence_count;
// //   std::cin >> N >> L;

// //   // read the positions of the first house from input
// //   int Si, Ti;
// //   std::cin >> Si >> Ti;

// //   // initialize the first fence position to the start of the first house
// //   int fence_pos = Si;

// //   // iterate through the houses
// //   for (int i = 2; i <= N; i++) {
// //     // read the positions of the current house from input
// //     std::cin >> Si >> Ti;

// //     // if the current fence does not cover the current house, place a new fence
// //     if (fence_pos + L < Si) {
// //       fence_pos = Si;
// //       fence_count++;
// //     }
// //   }

// //   // print the result
// //   std::cout << fence_count << std::endl;

// //   return 0;
// // }

// // create a graph with N vertices (train stations)
// int main()
// {
//     Graph graph(N);

//     // read M from input
//     int M;
//     cin >> M;

//     // read the routes from input and add them to the graph
//     for (int i = 1; i <= M; i++)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;
//         graph.addEdge(u, v, w);
//     }

//     // read Q from input
//     int Q;
//     cin >> Q;

//     // iterate through the passengers
//     for (int i = 1; i <= Q; i++)
//     {
//         // read the ticket level and the starting and ending stations
//         int L, s, t;
//         cin >> L >> s >> t;

//         // check if the passenger can travel from s to t
//         if (canTravel(graph, s, t, L))
//         {
//             cout << "yes" << endl;
//         }
//         else
//         {
//             cout << "no" << endl;
//         }
//     }

//     bool canTravel(Graph & graph, int s, int t, int L)
//     {
//         // create a queue for BFS
//         queue<int> q;
//         // create a visited array to mark visited vertices
//         vector<bool> visited(graph.numVertices(), false);
//         // create a distances array to store the distances from the starting vertex
//         vector<int> distances(graph.numVertices(), INT_MAX);

//         // mark the starting vertex as visited and enqueue it
//         visited[s] = true;
//         distances[s] = 0;
//         q.push(s);

//         // iterate through the queue
//         while (!q.empty())
//         {
//             // dequeue the front vertex
//             int u = q.front();
//             q.pop();

//             // iterate through the adjacency list of the vertex
//             for (auto edge : graph.adjList(u))
//             {
//                 int v = edge.vertex;
//                 int w = edge.weight;

//                 // if the edge weight is greater than or equal to the ticket level, continue
//                 if (w < L)
//                     continue;

//                 // if the vertex has not been visited, mark it as visited and enqueue it
//                 if (!visited[v])
//                 {
//                     visited[v] = true;
//                     distances[v] = distances[u] + 1;
//                     q.push(v);
//                 }
//             }
//         }

//         // return whether the ending vertex was visited
//         return visited[t];
//     }
// }

// #include<iostream>
// using namespace std;

// int main(){

//     def can_travel(N, M, Q, routes, passengers):
//   # Create an adjacency list to represent the graph of train stations and their connections
//   adjacency_list = [[] for _ in range(N)]
//   for (Ai, Bi, Ci) in routes:
//     # Add the connection from Ai to Bi with minimum ticket level Ci
//     adjacency_list[Ai-1].append((Bi-1, Ci))
//     # Add the connection from Bi to Ai with minimum ticket level Ci
//     adjacency_list[Bi-1].append((Ai-1, Ci))

//     return 0;
// }

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 3e3 + 5;
const int MAXM = 3e4 + 5;
const int MAXQ = 10 + 5;
const int MAXL = 1e5 + 5;

int N, M, Q;
vector<pair<int, int>> adjacency_list[MAXN];

bool can_travel(int Li, int Si, int Ti)
{
    // Initialize a queue for the breadth-first search
    queue<int> queue;
    // Initialize a set to keep track of the stations that have been visited
    vector<bool> visited(N);

    // Add the starting station to the queue
    queue.push(Si);
    // Mark the starting station as visited
    visited[Si] = true;

    // Perform the breadth-first search
    while (!queue.empty())
    {
        // Get the next station from the queue
        int current_station = queue.front();
        queue.pop();

        // Check if we have reached the destination station
        if (current_station == Ti)
        {
            // If we have reached the destination, it means we can travel from Si to Ti
            return true;
        }

        // Iterate through the connections of the current station
        for (auto [next_station, min_ticket_level] : adjacency_list[current_station])
        {
            // Check if the passenger's ticket level is sufficient to travel through this connection
            if (Li >= min_ticket_level && !visited[next_station])
            {
                // If the ticket level is sufficient and the next station has not been visited,
                // add it to the queue and mark it as visited
                queue.push(next_station);
                visited[next_station] = true;
            }
        }
    }

    // If the queue is empty and we have not reached the destination, it means we cannot travel
    // from Si to Ti with the given ticket level
    return false;
}

int main()
{
    cin >> N >> M >> Q;

    // Read the routes
    for (int i = 0; i < M; i++)
    {
        int Ai, Bi, Ci;
        cin >> Ai >> Bi >> Ci;
        // Add the connection from Ai to Bi with minimum ticket level Ci
        adjacency_list[Ai - 1].emplace_back(Bi - 1, Ci);
        // Add the connection from Bi to Ai with minimum ticket level Ci
        adjacency_list[Bi - 1].emplace_back(Ai - 1, Ci);
    }

    // Read the passenger information
    for (int i = 0; i < Q; i++)
    {
        int Li, Si, Ti;
        cin >> Li >> Si >> Ti;
        if (can_travel(Li, Si - 1, Ti - 1))
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }

    return 0;
}