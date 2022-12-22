#include <iostream>
using namespace std;

char map_graph[30][30];

bool seen[30][30];
int n, m;
bool check_star = false;
bool check_dollor = false;
int felids_1 = 0;
int felids_2 = 0;

int dfs(int a, int b)
{
    if (seen[a][b])
    {
        return 0;
    }
    if (a < 0 or a >= n or b < 0 or b >= m)
    {
        return 0;
    }
    seen[a][b] = true;
    if (map_graph[a][b] == '#')
    {
        return 0;
    }
    if (map_graph[a][b] == '*')
    {
        check_star = true;
    }
    else if (map_graph[a][b] == '$')
    {
        check_dollor = true;
    }
    int sum = 1;
    sum += dfs(a, b + 1);
    sum += dfs(a + 1, b);
    sum += dfs(a - 1, b);
    sum += dfs(a, b - 1);
    return sum;
}
void run_graph(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!seen[i][j])
            {
                check_star = false;
                check_dollor = false;
                int count = dfs(i, j);
                if (check_star and check_dollor)
                {
                    felids_1 += count;
                }
                else if (check_star or check_dollor)
                {
                    felids_2 += count;
                }
            }
        }
    }
    cout << felids_1 << " " << felids_2;
}

void init_graph(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map_graph[i][j];
        }
    }
}
int main()
{
    cin >> n >> m;
    init_graph(n, m);
    run_graph(n, m);
}