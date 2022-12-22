#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Box
{
    int green;
    int black;
    int net; // net value of the box

    // comparison operator to sort boxes in decreasing order of net value
    bool operator<(const Box &other) const
    {
        return net > other.net;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;

    // read the boxes
    vector<Box> boxes;
    for (int i = 0; i < n; i++)
    {
        int green, black;
        cin >> green >> black;

        boxes.push_back({green, black, green - black});
    }

    // sort the boxes in decreasing order of net value
    sort(boxes.begin(), boxes.end());

    // throw away the first k boxes
    for (int i = 0; i < k; i++)
    {
        boxes.pop_back();
    }

    // calculate the total earnings
    int earnings = 0;
    for (const auto &box : boxes)
    {
        earnings += box.net;
    }

    cout << earnings << endl;

    return 0;
}