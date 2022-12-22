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
bool ans = false;

void bfs(int start)
{

    // q.push(start);
    // seen[start] = true;
    // while (!q.empty())
    // {
    //     int u_current = q.front();
    //     q.pop();
    //     for (int v : adj[u_current])
    //     {
    //         // if (can_go)
    //         // return;
    //         int color_member = 0;
    //         cout<<color_member;
    //         if (color[u_current] == 0)
    //         {
    //             color_member = 1;
    //         }
    //         if (!seen[v])
    //         {
    //             color[v] = color_member;
    //             seen[v] = true;
    //             q.push(v);
    //         }
    //     }
    // }
    // for(int a : color)
    // {
    //     cout<< a<< "  " ;
    // }
    // cout<< endl;
    // memset(seen, false, sizeof(seen));
    // q.push(start);
    // seen[start] = true;
    // while (!q.empty())
    // {
    //     int u_current = q.front();
    //     q.pop();
    //     for (int v : adj[u_current])
    //     {
    //         if (can_go)
    //             return;

    //         if (!seen[v])
    //         {
    //             seen[v] = true;
    //             q.push(v);
    //             if (color[u_current] == color[v])
    //             {
    //                 can_go = true;
    //                 continue;
    //             }
    //         }
    //     }
    // }
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
        bfs(0);
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