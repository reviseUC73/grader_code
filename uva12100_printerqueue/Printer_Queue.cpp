#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            int p;
            cin >> p;
            q.push({p, i});
        }
        int time = 0;
        while (true)
        {
            int p = q.front().first;
            int idx = q.front().second;
            q.pop();
            bool can_print = true;
            queue<pair<int, int>> temp_q = q;
            while (!temp_q.empty())
            {
                if (temp_q.front().first > p)
                {
                    can_print = false;
                    break;
                }
                temp_q.pop();
            }
            if (can_print)
            {
                time++;
                if (idx == m)
                {
                    cout << time << endl;
                    break;
                }
            }
            else
            {
                q.push({p, idx});
            }
        }
    }
    return 0;
}
