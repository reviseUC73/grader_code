#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int table[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> table[i][j];
        }
    }

    int sumRow[n];
    for (int i = 0; i < n; i++)
    {
        sumRow[i] = 0;
        for (int j = 0; j < n; j++)
        {
            sumRow[i] += table[i][j];
        }
    }

    int sumColumn[n];
    for (int i = 0; i < n; i++)
    {
        sumColumn[i] = 0;
        for (int j = 0; j < n; j++)
        {
            sumColumn[i] += table[j][i];
        }
    }

    int focusedSum = sumRow[0];
    for (int i = 1; i < n; i++)
    {
        if (sumRow[i] != focusedSum)
        {
            for (int j = 0; j < n; j++)
            {
                if (sumColumn[j] != focusedSum)
                {
                    cout << table[i][j] << endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}
