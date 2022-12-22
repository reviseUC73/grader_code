#include <iostream>

using namespace std;

const int MAX_N = 1000;

int N, W;
int C[MAX_N + 1]; // values of the coupons

int main()
{
    cin >> N >> W;

    for (int i = 1; i <= N; i++)
    {
        cin >> C[i];
    }

    // array to store the number of coupons for each type
    int numCoupons[MAX_N + 1] = {0};

    // give out coupons starting from the highest value
    for (int i = N; i >= 1; i--)
    {
        while (W >= C[i])
        { // give out as many coupons as possible
            W -= C[i];
            numCoupons[i]++;
        }
    }

    // print the number of coupons for each type
    for (int i = 1; i <= N; i++)
    {
        cout << numCoupons[i] << " ";
    }
    cout << endl;

    return 0;
}
