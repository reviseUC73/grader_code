
#include <vector>
#include <iostream>
using namespace std;

char grid_graph[150][150];


int dfs_gride(int u, int v, int area)
{
    if (u >= 0 and v >= 0 and u <= area and v <= area)
    {
        // grid_graph[u][v] = '.'; // being checked or used
        // int k = 0;
        if (grid_graph[u][v] == 'x' or grid_graph[u][v] == '@')
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
                    // cout << grid_graph[u][v] << endl;

                    yo = dfs_gride(u, v, area);

                }
                ans += yo;
            }
        }
        cout << "Case " << case_+1 << ": " << ans << endl;
    }
}