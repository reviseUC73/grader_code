#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 110;

int n, m, s;
char arena[MAXN][MAXN];                                 // The map of the arena
int x, y, dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}; // x, y: current position; dx, dy: movements in each direction
char instructions[50001];                               // The instructions for the robot

int main()
{
    while (true)
    {
        cin >> n >> m >> s;
        if (n == 0 && m == 0 && s == 0)
            break; // Stop the program when all inputs are 0

        // Read in the map of the arena
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arena[i][j];
                if (arena[i][j] == 'N' || arena[i][j] == 'S' || arena[i][j] == 'L' || arena[i][j] == 'O')
                {
                    x = i;
                    y = j; // Set the initial position of the robot
                }
            }
        }

        // Read in the instructions for the robot
        for (int i = 0; i < s; i++)
        {
            cin >> instructions[i];
        }

        // Set the initial direction of the robot
        int d = 0; // 0: North; 1: East; 2: South; 3: West
        if (arena[x][y] == 'N')
            d = 0;
        else if (arena[x][y] == 'L')
            d = 1;
        else if (arena[x][y] == 'S')
            d = 2;
        else if (arena[x][y] == 'O')
            d = 3;

        int count = 0; // The number of stickers collected by the robot
        for (int i = 0; i < s; i++)
        {
            if (instructions[i] == 'D')
                d = (d + 1) % 4; // Turn right
            else if (instructions[i] == 'E')
                d = (d + 3) % 4; // Turn left
            else
            {
                // Try to move forward
                int nx = x + dx[d], ny = y + dy[d];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && arena[nx][ny] != '#')
                {
                    // The move is valid, update the current position
                    x = nx;
                    y = ny;
                    if (arena[x][y] == '*')
                    {
                        // Collect the sticker
                        count++;
                        arena[x][y] = '.';
                    }
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}
