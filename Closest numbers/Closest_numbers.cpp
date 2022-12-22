#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int min = 0, n = 0;
    cin >> n;
    int box[n];

    for (int i = 0; i < n; i++)
    {   int put =0;
        cin >> box[i];
    }
    sort(box, box + n);
    min = abs(box[1] - box[0]);
    for (int i = 0; i < n - 1; i++)
    {
        int yo = abs(box[i + 1] - box[i]);
        if (yo < min)
        {
            min = yo;
        }
    }
    cout << min;
    //     min = abs(box[1]-box[0]);
    //     for (int i = 0; i < n; i++)
    //     {
    //         for (int j = i+1; j < n; j++)
    //         {
    //             int yo;
    //             yo = abs(box[i] - box[j]);
    //             if (min > yo)
    //             {
    //                 min = yo;
    //             }
    //         }
    //     }
    //     cout << min;
}
