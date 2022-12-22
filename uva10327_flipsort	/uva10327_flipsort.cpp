#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int flip_count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (a[j] > a[j + 1])
                {
                    swap(a[j], a[j + 1]);
                    flip_count++;
                }
            }
        }

        cout << "Minimum exchange operations : " << flip_count << endl;
    }

    return 0;
}