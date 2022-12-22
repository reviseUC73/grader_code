#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int v[10010];
    int n, m, max, price1, price2, diff, tmp;

    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        cin >> m;

        sort(v, v + n); // sort the prices in ascending order

        max = 1000000;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if ((v[i] + v[j]) == m)
                {
                    diff = abs(v[i] - v[j]);
                    if (diff < max)
                    {
                        max = diff;
                        price1 = v[i];
                        price2 = v[j];
                    }
                }
            }
        }

        if (price1 > price2)
        {
            tmp = price1;
            price1 = price2;
            price2 = tmp;
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n", price1, price2);
    }

    return 0;
}
