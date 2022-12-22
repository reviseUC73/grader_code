#include <cstdio>
#include <algorithm>
#include <iostream>
#include <climits> // add this line

using namespace std;

const int N = 10020;
int arr[N], n, m;
int main()
{
    bool f = 0;
    while (cin >> n)
    {
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        cin >> m;
        sort(arr, arr + n);
        int mn = INT_MAX, a, b; // remove the problem
        for (int k = 0; k < n; ++k)
        {
            int sum = arr[k];
            int id = -1;
            for (int i = 0; i < n; ++i)
            {
                if (arr[i] == m - sum && i != k)
                {
                    id = i;
                    break;
                }
            }
            if (id != -1)
            {
                if (abs(id - k) < mn)
                {
                    mn = abs(id - k);
                    a = arr[id];
                    b = arr[k];
                }
            }
        }
        if (a > b)
        {
            swap(a, b);
        }
        cout << "Peter should buy books whose prices are " << a << " and " << b << "." << endl;
        //  puts("");
        cout << endl;
    }
    return 0;
}