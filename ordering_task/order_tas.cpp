#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 110;

vector<int> adj[MAX_N];
int indeg[MAX_N];
int outdeg[MAX_N];
int n, m;

vector<int> output;
    
void read_input()
{
    cin >> n >> m;
    if ((n == 0) && (m == 0))
        return;

    for (int i = 0; i < n; i++)
    {
        indeg[i] = outdeg[i] = 0; // number of node init val vec
        adj[i].clear();
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        indeg[v]++;
        outdeg[u]++;
    }
}

void topo_order()
{
    vector<int> s;

    output.clear();

    for (int u = 0; u < n; u++)
        if (indeg[u] == 0)
        {
            s.push_back(u);
        }
    for (int i = 0; i < n; i++)
    {
        int u = s.back();
        s.pop_back();
        output.push_back(u);

        for (int d = 0; d < outdeg[u]; d++)
        {
            int v = adj[u][d];
            indeg[v]--;
            if (indeg[v] == 0)
            {
                s.push_back(v);
            }
        }
    }
}

int main()
{
    while (true)
    {
        read_input();
        if (n == 0 and m == 0)
        {
            return 0;
        }
        topo_order();
        for (int i = 0; i < n; i++)
        {
            cout << output[i] << " ";
        }
        cout<< endl;
    }
}