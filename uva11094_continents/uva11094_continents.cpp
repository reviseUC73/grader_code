
#include <vector>
#include <iostream>
using namespace std;
// int contant Max = 150;
char grid_graph[150][150];
bool vis_seen[150][150];
int row, col;
int total = 0;
int sum = 0;
// int dfs_gride(int u, int v, int x, int y, char point)
// {
//     if (u >= 0 and v >= 0 and u <= y and v <= x)
//     {
//         if (grid_graph[u][v] == 'x' or grid_graph[u][v] == '@')
//         {
//             grid_graph[u][v] = '.';
//             dfs_gride(u + 1, v, x, y, point); // right
//             dfs_gride(u - 1, v, x, y, point); // left
//             dfs_gride(u, v + 1, x, y, point); // up
//             dfs_gride(u, v - 1, x, y, point); // down
//             return 1;
//         }
//         else
//         {
//             return 0;
//         }
//     }
// }
void look_bool(int num,int x,int y)
{
    if (num == 2)
    {
        for (int i = 0; i<5 ; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cout << vis_seen[i][j];
            }
            cout << endl;
        }
    cout << endl;
    }

    else
    {
        for (int j = 0; j < 10000; j++)
        {
            cout << j;
        }
    }
}
// int dfs(int x, int y, char text)
// {
//     if (!vis_seen[x][y])
//     {
//         vis_seen[x][y] = true;
//         if (text == grid_graph[x][y])
//         {
//         }
//         // if (text == vis_seen[x][y] and !vis_seen[x][y])
//         // {

//         // }
//     }
//     // if(y >= m)
//     //     y = 0;
//     int sum = 0;
//     // char curret_chr = grid_graph[x][y];
//     // total += curret_chr;
// }



//x == col and y == row
void dfs_init(int x, int y, char text)
{   
    if(y < 0)
        y = row - 1;
    if(y >= row)
        y = 0;
    if (x <= col and x>=0)
    // if (x <= col and y <= row)
    {   
        // cout<<vis_seen[x][y] <<grid_graph[x][y]<<text<<endl;

        if (!vis_seen[x][y] and grid_graph[x][y] == text)
        {   
            // printf("WARNING:");
            vis_seen[x][y] = true;
            sum += 1;
            // if(grid_graph[0][y]==grid_graph[col-1][y]) // same y == row
            // {
            //     dfs_init(0,y,text);
            //     dfs_init(col-1,y,text);

            // }
            dfs_init(x + 1, y, text);
            dfs_init(x - 1, y, text);
            dfs_init(x, y + 1, text);
            dfs_init(x, y - 1, text);
        }
    // if()
    }
    // return grid_graph[x][y];
}
void set_bool()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            vis_seen[i][j] = false;
        }
        
    }
}
void graph_init(int col)
{
    for (int i = 0; i < col; i++)
    {
        cin >> grid_graph[i];
    }
}

int main()
{
    while (cin >> col >> row)
    {
        graph_init(col);
        set_bool();
        int x, y, total = 0;
        cin >> x >> y;
        // dfs(x, y, grid_graph[x][y]);
        char text = grid_graph[x][y];
        dfs_init(x, y, text);
        // look_bool(2,x,y);
        for (int i = 0; i < col; i++)
        {
            for (int j = 0; j < row; j++)
            {
                sum  = 0;
                dfs_init(i, j, text);
                // look_bool(2,x,y);
                // cout<<sum<<"hh"<<endl;
                if (sum > total)
                {
                    // cout<<sum<<endl;
                    total = sum;
                }
            }
        }
    cout << total << endl;
    // cout<<"to";

    }
}