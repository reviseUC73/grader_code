#include <iostream>
using namespace std;

int main()
{

    int n = 0, total = 0, diff = 0;
    cin >> n;
    cin >> total;
    cin >> diff;
    int count = 0;
    int box[100000];
    for (int i = 0; i < n; i++)
    {
        int yo = 0;
        cin >> yo;
        box[i] = yo;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (box[i] + box[j] >= total and abs(box[i] - box[j]) <= diff)
            {
                count++;
            }
        }
    }
    cout << count;
}