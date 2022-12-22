#include <cstdio>
#include <vector>
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int Case, Max, a, b;
// vector<int> graph;
vector<int> sum;
vector<bool> check_vis;
char grid_graph[150][150];
int dx = {};
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

int dfs_gride()
{
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

char init_graph(int area)
{
    for (int i = 0; i < area; i++)
    {
        for (int j = 0; j < area; j++)
        {
            cin >> grid_graph[i][j];
        }
        // cout<< grid_graph[i]<<endl;
    }
}

int main()
{
    int z;
    cin >> z;
    int full = z;
    z += 1;
    while (--z)
    {
        cout << z << endl;

        cout << "Round >> " << full - z << " area : ";
        int area;
        cin >> area;
        init_graph(area);
        cout << grid_graph[1] << endl;
    }
}