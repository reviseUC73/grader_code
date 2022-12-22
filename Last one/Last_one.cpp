#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;

    // Initialize the array of people
    int people[n];
    for (int i = 0; i < n; i++)
    {
        people[i] = i + 1;
    }

    // Keep track of the current index and the number of people left
    int index = 0;
    int num_people = n;

    // While there are still people left to introduce themselves
    while (num_people > 0)
    {
        // Increment the index by k - 1, wrapping around if necessary
        index = (index + k - 1) % num_people;

        // Remove the person at the current index from the circle
        for (int i = index; i < num_people - 1; i++)
        {
            people[i] = people[i + 1];
        }
        num_people--;
    }

    // The last person left is the one who introduces themselves last
    cout << people[0] << endl;
    return 0;
}