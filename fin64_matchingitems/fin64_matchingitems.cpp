#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, q;
int prices[N];

int main()
{
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        cin >> prices[i];
    }

    while (q--)
    {
        int x, y;
        cin >> x >> y;

        // Find the index of the most expensive item that the customer can get for free
        int index = upper_bound(prices + 1, prices + n + 1, prices[x] + y) - prices - 1;

        cout << index << endl;
    }

    return 0;
}