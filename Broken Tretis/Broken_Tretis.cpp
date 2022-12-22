#include <iostream>
using namespace std;

int main()
{
    int table[1000] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int n = 0;
    cin >> n;
    string type;
    int col;
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> type >> col;
        col = col - 1;
        if (type == "-")
        {
            int pos_max = col;
            for (int term = col; term < col + 4; term++)
            {
                if (table[term] > table[pos_max])
                {
                    pos_max = term;
                }
            }
            int val = table[pos_max];
            table[col] = val + 1;
            table[col + 1] = val + 1;
            table[col + 2] = val + 1;
            table[col + 3] = val + 1;
        }
        else if (type == "o")
        {
            int pos_max = col;
            for (int term = col; term < col + 2; term++)
            {
                if (table[term] > table[pos_max])
                {
                    pos_max = term;
                }
            }
            int val = table[pos_max];
            table[col] = val + 2;
            table[col + 1] = val + 2;
        }
        else if (type == "i")
        {
            table[col] += 4;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        if (table[i] > max)
        {
            max = table[i];
        }
    }
    cout << max;
}