#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
const int MAX = 20;
bool seen[MAX];
vector<int> adj[MAX];
queue<int> q;
bool can_go = false;
int color[MAX] = {0};
// bool ans = false;
char chage_color = 'a';
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
    }
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
            u--;
            v--;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if (can_go)
        {
            cout << "no" << endl;
        }
        else
        {
            cout << "yes" << endl;
        }
    }
}