#include <bits/stdc++.h>
#include <iostream>
// using namespace std;
using namespace std;

int main()
{
    int n, x0, y0, x, y;
    while (~scanf("%d", &n) && n)
    {
        scanf("%d%d", &x0, &y0);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &x, &y);
            if (x == x0 || y == y0)
                printf("divisa\n");
            else if (x < x0 and y < y0)
                printf("SO\n");
            else if (x < x0 and y > y0)
                printf("NO\n");
            else if (x > x0 and y < y0)
                printf("SE\n");
            else if (x > x0 and y > y0)
                printf("NE\n");
        }
    }

}
