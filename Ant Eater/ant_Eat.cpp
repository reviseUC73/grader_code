#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int box[n];
    for (int i = 0; i < n; i++)
    {
        int enter = 0;
        cin >> enter;
        if (enter >= 1000)
        {
            box[i] = 1000;
            i += 1;
            cin >> enter;
            box[i] = 0;
        }
        else
        {
            box[i] = enter;
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cout << box[i] << endl;
        sum += box[i];
    }
    cout << sum;
}