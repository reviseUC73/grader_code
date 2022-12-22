#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

const int MAX_N = 100000;

int N;
int a[MAX_N + 1]; // sequence of integers

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    map<int, int> freq; // map to store the frequencies of the differences

    // calculate the differences between consecutive integers and the differences between the ith and (i+2)-th integers
    for (int i = 0; i < N - 1; i++)
    {
        freq[abs(a[i] - a[i + 1])]++;
    }
    for (int i = 0; i < N - 2; i++)
    {
        freq[abs(a[i] - a[i + 2])]++;
    }

    // find the most frequent integer
    int maxFreq = 0;
    int secret = 0;
    for (auto p : freq)
    {
        if (p.second > maxFreq)
        {
            maxFreq = p.second;
            secret = p.first;
        }
        else if (p.second == maxFreq)
        {
            secret = min(secret, p.first);
        }
    }

    cout << secret << endl;

    return 0;
}