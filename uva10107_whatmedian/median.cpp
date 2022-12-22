#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> list;
    
int main()
{
    while (cin >> n)
    {
        list.push_back(n);
        sort(list.begin(), list.end());
        if (list.size() % 2 == 0)
        {
            cout << (list[list.size() / 2] + list[list.size() / 2 - 1]) / 2 << endl;
        }
        else
            cout << list[list.size() / 2] << endl;
    }
}
