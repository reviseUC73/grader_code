#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, d, r;
    while (cin >> n >> d >> r)
    {
        if (n == 0 && d == 0 && r == 0)
            break;

        vector<int> m(n), e(n);
        for (int i = 0; i < n; i++)
            cin >> m[i];
        for (int i = 0; i < n; i++)
            cin >> e[i];

        sort(m.begin(), m.end());
        sort(e.rbegin(), e.rend());

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int overtime = max(0, m[i] + e[i] - d);
            sum += overtime;
        }

        cout << sum * r << endl;
    }

    return 0;
}
