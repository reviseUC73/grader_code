#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  int case_;
  cin >> case_;

  while (case_--)
  {
    vector<vector<int>> g(9, vector<int>(9, 0));

    for (int i = 0; i < 9; i += 2)
    {
      for (int j = 0; j <= i; j += 2)
      {
        cin >> g[i][j];
      }
    }

    int a, b, c;
    for (int i = 8; i > 0; i -= 2)
    {
      for (int j = 0; j < i; j += 2)
      {
        a = g[i][j], b = g[i][j + 2];
        c = g[i - 2][j];
        g[i][j + 1] = (c - a - b) / 2;
        g[i - 1][j] = g[i][j] + g[i][j + 1];
        g[i - 1][j + 1] = g[i][j + 1] + g[i][j + 2];
      }
    }

    for (int i = 0; i < 9; i++)
    {
      for (int j = 0; j <= i; j++)
      {
        cout << g[i][j];
        if (j < i)
        {
          cout << " ";
        }
      }
      cout << endl;
    }
  }

  return 0;
}
