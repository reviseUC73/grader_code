// #include <iostream>
// #include <vector>

// using namespace std;

// int main() {
//   // Read in n and m
//   int n, m;
//   cin >> n >> m;

//   // Read in the colors of the original balls
//   vector<int> balls(n);
//   for (int i = 0; i < n; i++) {
//     cin >> balls[i];
//   }

//   // Read in the colors and positions of the balls to be added
//   for (int i = 0; i < m; i++) {
//     int color, position;
//     cin >> color >> position;
//     balls.insert(balls.begin() + position + 1, color);
//   }

//   // Print the final sequence of ball numbers
//   for (int i = 0; i < balls.size(); i++) {
//     cout << i + 1 << " ";
//   }

//   return 0;
// }

#include <iostream>
using namespace std;

const int MAX_N = 2000100;

int c[MAX_N];

int balls[MAX_N];
int ball_count = 0;

void insert_end(int lst[], int &s, int val)
{
    lst[s] = val;
    s++;
}

int find(int lst[], int s, int target)
{
    for (int i = 0; i < s; i++)
    {
        if (lst[i] == target)
            return i;
    }

    return -1;
}

int insert(int lst[], int &s, int val, int loc)
{
    if (loc < 0 || loc > s)
        return -1;

    for (int i = s; i > loc; i--)
    {
        lst[i] = lst[i - 1];
    }

    lst[loc] = val;
    s++;
    return 0;
}

int main()
{
    int n, m;
    int d, p;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
        insert_end(balls, ball_count, i + 1);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> d >> p;

        int idx = find(balls, ball_count, p);
        insert(balls, ball_count, i + n + 1, idx + 1);
    }

    for (int i = 0; i < ball_count; i++)
    {
        cout << balls[i] << endl;
    }

    return 0;
}