#include <iostream>
#include <list>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    // Create a list of integers
    list<int> cards;
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        cards.push_back(value);
    }

    // Get an iterator to the first element in the list
    list<int>::iterator it = cards.begin();

    for (int i = 0; i < m; i++)
    {
        int target, sum;
        cin >> target;
        sum = 0;
        while (true)
        {
            sum += *it;
            if (sum >= target)
            {
                // Drop the current card
                it = cards.erase(it);
                if (it == cards.end())
                {
                    // If we reached the end of the list, set the iterator
                    // to the beginning of the list
                    it = cards.begin();
                }
                break;
            }
            it++;
            if (it == cards.end())
            {
                // If we reached the end of the list, set the iterator
                // to the beginning of the list
                it = cards.begin();
            }
        }
    }

    // Print the remaining cards
    for (int card : cards)
    {
        cout << card << endl;
    }
    return 0;
}
