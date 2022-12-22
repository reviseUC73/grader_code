#include <iostream>
#include <vector>
#include <list>

using namespace std;

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <math.h>
using std::cin;
using std::cout;
using std::endl;
using std::sqrt;
using std::vector;

struct Point
{
    int x;
    int y;
    // float ds = sqrt(pow(x, 2) + pow(y, 2));
    Point(int x = 0, int y = 0)
        : x(x), y(y) {}
};
int distance(Point *p1, Point *p2)
{
    return sqrt(pow((p2->x - p1->x), 2) + pow((p2->y - p1->y), 2));
}

int main()
{
    // Point *yo = new Point(3, 4);
    // cout << yo->ds;
    int n, r;
    cin >> n;
    cin >> r;
    vector<Point> yo;
    // Point *first = new Point(0, 0);
    Point first;
    first = Point(0, 0);
    yo.push_back(first);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x;
        cin >> y;
        Point co;
        co = Point(x, y);
        yo.push_back(co);
    }
    
}
// int dist_cal(vector<int> &, int);

// int main()
// {
//     int num_pairs = -1;
//     cout << "Enter the number of pairs of point co-ordinates (x, y) that you want to enter: " << endl;
//     cin >> num_pairs;

//     vector<int> points;
//     cout << "Now enter the (x, y) co-ordinate pairs: " << endl;
//     for (int i = 0; i < num_pairs * 2; i++)
//     {
//         int buff;
//         cin >> buff;
//         points.push_back(buff);
//     }

//     cout << "The minimum distance between the array of points entered is " << dist_cal(points, num_pairs) << "." << endl;
//     return 0;
// }

// int dist_cal(vector<int> &arr, int num_pairs)
// {
//     cout << "yp" << endl;
//     int min_distance = -1, temp_distance = -1, x1, x2, y1, y2, itr_count = 0;
//     for (int i = 0; i <= num_pairs; i += 2)
//     {
//         // x1 = arr[i + 0];
//         // x2 = arr[i + 1];
//         x1 = arr[i + 0];
//         y1 = arr[i + 1];
//         for (int j = i + 2; j <= num_pairs; j += 2)
//         {
//             y1 = arr[j + 0];
//             y2 = arr[j + 1];
//             temp_distance = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

//             if (itr_count == 0)
//             {
//                 min_distance = temp_distance;
//                 itr_count++;
//             }
//             if (min_distance > temp_distance)
//             {
//                 min_distance = temp_distance;
//             }
//         }
//     }
//     return min_distance;
// }