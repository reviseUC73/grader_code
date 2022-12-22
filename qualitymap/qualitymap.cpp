// #include <iostream>
// using namespace std;

// char map_data[30][30];

// bool seen[30][30];
// int n, m;

// bool is_found_star = false;
// bool is_found_dollor = false;

// int dfs(int a, int b) {
//   if (seen[a][b]) {
//     return 0;
//   }
//   if (a < 0 || a >= n || b < 0 || b >= m) {
//     return 0;
//   }
//   // cout << "Goto " << a << "-" << b << endl;
//   seen[a][b] = true;
//   if (map_data[a][b] == '#') {
//     // cout << "Found # at " << a << "-" << b << endl;
//     return 0;
//   }
//   if (map_data[a][b] == '*') {
//     is_found_star = true;
//     // cout << "Found * at " << a << "-" << b << endl;
//   } else if (map_data[a][b] == '$') {
//     is_found_dollor = true;
//     // cout << "Found $ at " << a << "-" << b << endl;
//   }
//   int sum = 1;
//   sum += dfs(a, b + 1);
//   sum += dfs(a + 1, b);
//   sum += dfs(a - 1, b);
//   sum += dfs(a, b - 1);
//   return sum;
// }

// int main() {
//   cin >> n >> m;
//   for (int i = 0; i < n; i++) {
//     string input;
//     cin >> input;
//     for (int j = 0; j < m; j++) {
//       map_data[i][j] = input[j];
//     }
//   }

//   int super = 0;
//   int medium = 0;

//   for (int i = 0; i < n; i++) {
//     for (int j = 0; j < m; j++) {
//       if (!seen[i][j]) {
//         // cout << "Start: " << i << "-" << j << endl;
//         int count = dfs(i, j);
//         if (is_found_star && is_found_dollor) {
//           // cout << "Add Super" << count << endl;
//           super += count;
//         } else if (is_found_star || is_found_dollor) {
//           // cout << "Add Medium" << count << endl;
//           medium += count;
//         }
//         is_found_star = false;
//         is_found_dollor = false;
//         // cout << "Here" << count << " Super: " << super << " Medium" <<
//         // endl;
//       }
//     }
//   }
//   int count = dfs(0, 5);
//   cout << super << " " << medium;

//   return 0;
// }

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

const int MAXN = 30;

char map_data[MAXN][MAXN];
bool seen[MAXN][MAXN];
int n, m;

bool is_found_star = false;
bool is_found_dollar = false;

int bfs(int a, int b)
{
    queue<pair<int, int>> q;
    q.push({a, b});
    seen[a][b] = true;
    int sum = 0;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x < 0 || x >= n || y < 0 || y >= m)
        {
            continue;
        }
        if (map_data[x][y] == '#')
        {
            continue;
        }
        if (map_data[x][y] == '*')
        {
            is_found_star = true;
        }
        else if (map_data[x][y] == '$')
        {
            is_found_dollar = true;
        }
        sum++;
        if (!seen[x][y + 1])
        {
            q.push({x, y + 1});
            seen[x][y + 1] = true;
        }
        if (!seen[x + 1][y])
        {
            q.push({x + 1, y});
            seen[x + 1][y] = true;
        }
        if (!seen[x - 1][y])
        {
            q.push({x - 1, y});
            seen[x - 1][y] = true;
        }
        if (!seen[x][y - 1])
        {
            q.push({x, y - 1});
            seen[x][y - 1] = true;
        }
    }
    return sum;
}

int main()
{
    cin >> n >> m;
    // for (int i = 0; i < n; i++)
    // {
    //     string input;
    //     cin >> input;
    //     for (int j = 0; j < m; j++)
    //     {
    //         map_data[i][j] = input[j];
    //     }
    // }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map_data[i][j];
        }
    }
    int super = 0;
    int medium = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!seen[i][j])
            {
                int count = bfs(i, j);
                if (is_found_star && is_found_dollar)
                {
                    super += count;
                }
                else if (is_found_star || is_found_dollar)
                {
                    medium += count;
                }
                is_found_star = false;
                is_found_dollar = false;
            }
        }
    }
    cout << super << " " << medium;

    return 0;
}
