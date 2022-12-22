#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Route
{
    int destination;
    int minLevel;
};

// Function to check if a passenger with level L can travel from city S to city T
bool canTravel(int N, vector<Route> *adjacencyList, int L, int S, int T)
{
    // Keep track of which cities have been visited
    vector<bool> visited(N);
    // Use a stack to store the cities to visit
    vector<int> stack;
    stack.push_back(S);
    while (!stack.empty())
    {
        int node = stack.back();
        stack.pop_back();
        if (node == T)
        {
            // We found a path from S to T, so the passenger can travel
            return true;
        }
        if (visited[node])
        {
            // We have already visited this city, so we can skip it
            continue;
        }
        visited[node] = true;
        // Add all the unvisited cities that the passenger can travel to to the stack
        for (Route route : adjacencyList[node])
        {
            int neighbor = route.destination;
            int minLevel = route.minLevel;
            if (!visited[neighbor] && L >= minLevel)
            {
                stack.push_back(neighbor);
            }
        }
    }
    // We reached the end of the search and didn't find a path from S to T, so the passenger cannot travel
    return false;
}

int main()
{
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<Route> adjacencyList[N];
    for (int i = 0; i < M; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        adjacencyList[A - 1].push_back({B - 1, C});
        adjacencyList[B - 1].push_back({A - 1, C});
    }
    vector<pair<int, pair<int, int>>> passengers;
    for (int i = 0; i < Q; i++)
    {
        int L, S, T;
        cin >> L >> S >> T;
        passengers.push_back({L, {S - 1, T - 1}});
    }

    for (auto &passenger : passengers)
    {
        int L = passenger.first;
        int S = passenger.second.first;
        int T = passenger.second.second;
        if (canTravel(N, adjacencyList, L, S, T))
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