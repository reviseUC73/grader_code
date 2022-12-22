#include <iostream>
using namespace std;

int d2(int num)
{
    return (num / 10) % 10;
}

int main()
{
    int n, time,num;
    cin >> time;
    int box[time];
    for (int i = 0; i < time; i++)
    {
        cin >> n;
        num = (((((n * 567) / 9) + 7492) * 235) / 47) - 498;
        box[i] =  abs(d2(num));
    }
    for (int i = 0; i < time; i++)
    {
        cout<<box[i]<<endl;
    }
}


