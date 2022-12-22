#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 30;

char map_data[MAXN][MAXN];
int n, m;

vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int dfs(int x, int y) {
  if (x < 0 || x >= n || y < 0 || y >= m || map_data[x][y] == '#') {
    return 0;
  }
  map_data[x][y] = '#';  // Mark the current cell as visited
  int count = 1;
  for (auto dir : dirs) {
    count += dfs(x + dir.first, y + dir.second);
  }
  return count;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string input;
    cin >> input;
    for (int j = 0; j < m; j++) {
      map_data[i][j] = input[j];
    }
  }

  int super = 0;
  int medium = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (map_data[i][j] == '*' || map_data[i][j] == '$') {
        int count = dfs(i, j);
        if (map_data[i][j] == '*') {
          medium += count;
        } else {
          super += count;
        }
      }
    }
  }
  cout << super << " " << medium;
  return 0;
}
