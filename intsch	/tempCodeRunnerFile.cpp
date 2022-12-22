#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int max_n = 100000;

int s[max_n];
int t[max_n];

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> work_index;

    for (int i = 0; i < n; i++)
    {
        cin >> s[i] >> t[i];
        work_index.emplace_back(t[i], i);
    }

    sort(work_index.begin(), work_index.end());
    int last_stop = -1;
    int count = 0;
    for (const auto &[t, i] : work_index)
    {
        if (s[i] >= last_stop)
        {
            count++;
            last_stop = t;
        }
    }
    cout << count << endl;
}
