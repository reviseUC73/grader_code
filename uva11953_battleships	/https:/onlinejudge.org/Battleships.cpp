#include <vector>
#include <iostream>
using namespace std;

// int Case, Max, a, b;
// vector<int> graph;
// vector<int> sum;
// vector<bool> check_vis;
char grid_graph[150][150];
// int dx = {};
// int dfs(int u)
// {
//     int total = 0;
//     check_vis[u] = true;
//     if (graph[u] != -1)
//     {
//         if (!check_vis[graph[u]])
//         {
//             total += (1 + dfs(graph[u]));
//         }
//     }
//     check_vis[u] = false;
//     return sum[u] = total;
// }

int dfs_gride(int u, int v, int area)
{
    if (u >= 0 and v >= 0 and u <= area and v <= area)
    {
        // grid_graph[u][v] = '.'; // being checked or used
        // int k = 0;
        if (grid_graph[u][v] == 'x')
        {
            // int k=0;
            grid_graph[u][v] = '.';
            dfs_gride(u + 1, v, area); // right
            dfs_gride(u - 1, v, area); // left
            dfs_gride(u, v + 1, area); // up
            dfs_gride(u, v - 1, area); // down
        }
        return 1;
    }
    else
    {
        return 0;
    }
}
// int total = 0;
// check_vis[u] = true;
// if (graph[u] != -1)
// {
//     if (!check_vis[graph[u]])
//     {
//         total += (1 + dfs_gride(graph[u]));
//     }
// }
// check_vis[u] = false;
// return sum[u] = total;

// char *init_graph(int area, char graph[])
// {
//     for (int i = 0; i < area; ++i)
//     {
//         cin >> graph[i];
//     }
//     return graph;
// }
///
// void bfs(int u)
// {
//     queue<int> q;
//     q.push(u);
//     check_vis[u] = true;
//     while (!q.empty())
//     {

//         for (int i = 0; i < grid[u].size(); i++)
//         {
//             char v = grid[u][i];
//             if (!check_vis[v])
//             {

//                 check_vis[v] = true;
//                 q.push(v);
//             }
//         }
//     }
// vector<int> G[N];
// bitset<N> vis;
// void dfs(int s)
// {
//     vis[s] = 1;
//     for (int t : G[s])
//     {
//         if (!vis[i])
//             dfs(i);
//     }
// }
// vector<int> G[N];
// bitset<N> vis;
// void bfs(int s)
// {
//     queue<int> q;
//     q.push(s);
//     vis[s] = 1;
//     while (!q.empty())
//     {
//         int v = q.front();
//         q.pop();
//         for (int t : G[v])
//         {
//             if (!vis[t])
//             {
//                 q.push(t);
//                 vis[t] = 1;
//             }
//         }
//     }
// }

// void dfs_grid()
// {
// }

// int dfs_gride2(int u, int v, int area)
// {
//     // ไล่จุดที่เป็นareaเกี่ยวกับแผนที่เพื่อไม่ให้เช็คซำ้ (Mark the area on the map to avoid double-checking.)
//     grid_graph[u][v] = '.';
//     if (u >= 0 and v >= 0 and u <= area and v <= area)
//     {
//         int yo = 1;
//         dfs_gride2(u + 1, v, area); // right
//         dfs_gride2(u - 1, v, area); // left
//         dfs_gride2(u, v + 1, area); // up
//         dfs_gride2(u, v - 1, area); // down

//         // cout <<
//     }
//     return 1;
// }

int main()
{
    int z;
    cin >> z;
    for (int case_ = 0; case_ < z; case_++)
    {
        int area;
        cin >> area;
        // char *x;
        int ans = 0;
        // x = init_graph(area, *grid_graph);
        for (int i = 0; i < area; ++i)
        {
            cin >> grid_graph[i];
        }

        // cout << x[2] << endl;
        for (int u = 0; u < area; u++)
        {
            for (int v = 0; v < area; v++)
            {
                int yo = 0;

                if (grid_graph[u][v] == 'x')
                {
                    cout << grid_graph[u][v] << endl;
                    // cout << "BEfore " << grid_graph[u] << endl;

                    yo = dfs_gride(u, v, area);

                    // cout << "AFter  " << grid_graph[u] << endl;
                }
                ans += yo;
            }
        }
        cout << "Case " << case_+1 << ": " << ans << endl;
    }
}