#include <iostream>
#include <vector>

using namespace std;

const int N = 200210;

// Number of vertices and edges
int n, m;

// Adjacency list representation of the graph
vector<int> adj[N];

// Color of each vertex (0 or 1)
int color[N];

// Determines if the graph is bipartite or not
bool is_bipartite = true;

void dfs(int u, int c)
{
    color[u] = c;
    for (int v : adj[u])
    {
        if (color[v] == -1)
        {
            dfs(v, 1 - c);
        }
        else if (color[v] == c)
        {
            is_bipartite = false;
        }
    }
}

int main()
{
    int k;
    cin >> k;
    // k += 1;
    for (int kk = 0; kk < k; kk++)
    {
        // cout << is_bipartite<<endl;
        // for(int j : )

        cin >> n >> m;

        // Read in the edges
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Initialize colors to -1 (not visited)
        fill(color, color + n, -1);

        // Run DFS on each unvisited vertex
        for (int u = 0; u < n; u++)
        {
            if (color[u] == -1)
            {
                // is_bipartite = false;

                // memset(color, 0, sizeof(color));
                // vector<int> adj[N];

                dfs(u, 0);
                // int color[N];

                // memset(color, 0, sizeof(color));
            }
        }

        // Check if the graph is bipartite
        if (is_bipartite)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
        for (auto &my : adj)
        {
            my.clear();
        }
        is_bipartite = true;
    }
}