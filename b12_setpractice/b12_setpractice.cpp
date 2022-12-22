// #include <iostream>
// #include <set>

// using namespace std;

// int main() {
//   // Read N and M
//   int N, M;
//   cin >> N >> M;

//   // Read the list of integers X1, X2, ..., XN
//   set<int> s;
//   for (int i = 0; i < N; i++) {
//     int x;
//     cin >> x;
//     s.insert(x);
//   }

//   // Process the queries Y1, Y2, ..., YM
//   for (int j = 0; j < M; j++) {
//     int y;
//     cin >> y;

//     // Find the integer Xi that minimizes |Xi - Yj|
//     auto it = s.lower_bound(y);
//     int x1, x2;
//     if (it == s.begin()) {
//       x1 = *it;
//       x2 = *++it;
//     } else if (it == s.end()) {
//       x1 = *--it;
//       x2 = *it;
//     } else {
//       x1 = *--it;
//       x2 = *++it;
//     }
//     int x = (abs(x1 - y) < abs(x2 - y)) ? x1 : x2;
//     // int x;
//     // if (abs(x1 - y) < abs(x2 - y)) {
//     //   x = x1;
//     // } else {
//     //   x = x2;
//     // }

//     // Print the result
//     cout << x << endl;
//   }

//   return 0;
// }

#include <iostream>
#include <set>
#include <cmath>

using namespace std;

int main()
{
    // Read N and M
    int N, M;
    cin >> N >> M;

    // Read the list of integers X1, X2, ..., XN
    set<int> s;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }

    // Process the queries Y1, Y2, ..., YM
    for (int j = 0; j < M; j++)
    {
        int y;
        cin >> y;

        // Find the integer Xi that minimizes |Xi - Yj|
        auto it = s.lower_bound(y);
        int x1, x2;
        if (it == s.begin())
        {
            x1 = *it;
            x2 = *++it;
        }
        else if (it == s.end())
        {
            x1 = *--it;
            x2 = *it;
        }
        else
        {
            x1 = *--it;
            x2 = *++it;
        }
        int x;
        if (abs(x1 - y) < abs(x2 - y))
        {
            x = x1;
        }
        else
        {
            x = x2;
        }

        // Print the result
        cout << x << endl;
    }

    return 0;
}
