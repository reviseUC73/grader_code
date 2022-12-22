#include <iostream>
using namespace std;

int main()
{
    int time = 0;
    cin >> time;
    int box[time + 1];
    box[0] = 0;
    int sum = 0;
    int stack = -1;
    for (int i = 1; i <= time; i++)
    {
        int h = 0;
        cin >> h;
        box[i] = h;
        if (box[i] - box[i - 1] > 0)
        {
            stack += 1;
            sum += box[i] - box[i - 1];
            sum += stack;
        }
        else{
            stack = -1;
        }
    }
    cout<<sum;
}