#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    while (cin)
    {
        int n;
        cin >> n;

        int prices[n];
        for (int i = 0; i < n; i++)
            cin >> prices[i];

        int m;
        cin >> m;

        // sort the prices in ascending order
        sort(prices, prices + n);

        // initialize variables to store the book prices
        int book1 = 0, book2 = 0;
        int minDiff = 1000001; // initialize minDiff to a large number

        // use two pointers to find the two books with the closest sum to m
        int left = 0, right = n - 1;
        while (left < right)
        {
            int sum = prices[left] + prices[right];
            if (sum == m)
            {
                book1 = prices[left];
                book2 = prices[right];
                break;
            }
            else if (sum < m)
            {
                // update book1 and book2 if the current sum is closer to m
                int diff = m - sum;
                if (diff < minDiff)
                {
                    minDiff = diff;
                    book1 = prices[left];
                    book2 = prices[right];
                }
                left++;
            }
            else
            {
                // update book1 and book2 if the current sum is closer to m
                int diff = sum - m;
                if (diff < minDiff)
                {
                    minDiff = diff;
                    book1 = prices[left];
                    book2 = prices[right];
                }
                right--;
            }
        }

        cout << "Peter should buy books whose prices are " << book1 << " and " << book2 << "." << endl;
        cout << endl; // print a blank line after each test case
    }

    return 0;
}
