#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
const int MAX = 200210;
bool seen[MAX];
vector<int> adj[MAX];
queue<int> q;
bool can_go = false;
int color[MAX];

// Function to check if a graph is bipartite or not
bool is_bipartite(int start)
{
    // Initialize colors
    memset(color, -1, sizeof(color));
    color[start] = 0;

    // Perform BFS from the start node
    q.push(start);
    seen[start] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            // If the color of the adjacent node is the same as the current node,
            // the graph is not bipartite
            if (color[u] == color[v])
            {
                return false;
            }

            // If the adjacent node has not been visited, assign it the opposite color
            // of the current node and add it to the queue
            if (color[v] == -1)
            {
                color[v] = 1 - color[u];
                q.push(v);
                seen[v] = true;
            }
        }
    }

    // If the BFS completes without finding any adjacent nodes with the same color,
    // the graph is bipartite
    return true;
}

int main()
{
    int k, n, m;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            // Decrement node indices because they are 1-indexed in the input
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Check if the graph is bipartite
        if (is_bipartite(0))
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }

        // Reset the graph for the next test case
        memset(seen, false, sizeof(seen));
        for (int i = 0; i < n; i++)
        {
            adj[i].clear();
        }
    }
}
