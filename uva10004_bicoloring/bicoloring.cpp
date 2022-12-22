#include <iostream>
#include <vector>

using namespace std;

const int N = 200210;

int n, m;

vector<int> adj[N];

int color[N];
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
    int n;
    
    while(cin >> n and n!=0)
    {   
        // cout<<"rfe"<<n<<endl;
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        fill(color, color + n, -1);
        for (int u = 0; u < n; u++)
        {
            if (color[u] == -1)
            {
                dfs(u, 0);
            }
        }

        // Check if the graph is bipartite
        if (is_bipartite)
        {
            cout << "BICOLORABLE." << endl;
        }
        else
        {
            cout << "NOT BICOLORABLE." << endl;
        }
        for (auto &my : adj)
        {
            my.clear();
        }
        is_bipartite = true;
    }
}