
#include <vector>
#include <iostream>
using namespace std;
// int contant Max = 150;
char grid_graph[150][150];
bool vis_seen[150][150];
int row, col;
int total = 0;
int sum = 0;

void dfs_init(int x, int y, char text)
{   
    if(y < 0)
        y = row - 1;
    if(y >= row)
        y = 0;
    if (x <= col and x>=0)
    {   

        if (!vis_seen[x][y] and grid_graph[x][y] == text)
        {   
            vis_seen[x][y] = true;
            sum += 1;
          
            dfs_init(x + 1, y, text);
            dfs_init(x - 1, y, text);
            dfs_init(x, y + 1, text);
            dfs_init(x, y - 1, text);
        }
    }
}
void set_bool()
{
    for (int i = 0; i < 150; i++)
    {
        for (int j = 0; j < 150; j++)
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
        char text = grid_graph[x][y];
        dfs_init(x, y, text);
        for (int i = 0; i < col; i++)
        {
            for (int j = 0; j < row; j++)
            {
                sum = 0;
                dfs_init(i, j, text);
                if (sum > total)
                {
                    total = sum;
                }
            }
        }
    cout << total << endl;

    }
}