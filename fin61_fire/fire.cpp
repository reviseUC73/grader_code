#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, r;
    cin >> n >> r;

    // Read in the positions of the garages
    int garage_pos[n];
    for (int i = 0; i < n; i++)
    {
        cin >> garage_pos[i];
    }

    sort(garage_pos, garage_pos + n);
    int count_fire = 1;
    int current_fire_pos = garage_pos[0];

    // Iterate through the remaining garage positions
    for (int i = 1; i < n; i++)
    {
        // If the current garage position is more than 2 * r away from the current fire station position,
        // we need to place a new fire station at this garage
        if (garage_pos[i] - current_fire_pos > 2 * r)
        {
            count_fire++;
            current_fire_pos = garage_pos[i];
        }
    }

    cout << count_fire;

    return 0;
}
