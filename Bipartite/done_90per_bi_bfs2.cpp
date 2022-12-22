#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
const int MAX = 203000;
bool seen[MAX];
vector<int> adj[MAX];
queue<int> q;
int color[MAX] = {0};

int n, m;

void input_graph()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        adj[i].clear();
    }
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Init seen
    for (int i = 0; i < n; i++)
    {
        seen[i] = false;
        color[i] = 0;
    }
}

bool is_bipartite(int s)
{
    q.push(s);
    seen[s] = true;
    color[s] = 1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];
            if (!seen[v])
            {
                seen[v] = true;
                color[v] = 3 - color[u];  // assign opposite color
                q.push(v);
            }
            else if (color[v] == color[u])  // if same color, return false
            {
                return false;
            }
        }
    }
    return true;  // if no conflicts, return true
}

int main()
{
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        input_graph();

        bool ans = true;
        for (int i = 0; i < n; i++)
        {
            if (!seen[i])
            {
                if (!is_bipartite(i))
                {
                    ans = false;
                    break;
                }
            }
        }

        if (ans)
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
