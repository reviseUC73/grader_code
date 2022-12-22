#include <iostream>

#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    int n, g, t;
    cin >> n >> g >> t;

    // Read the array of integers
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    // Initialize the left and right pointers
    int left = 0;
    int right = n - 1;

    // Initialize the count of pairs
    int count = 0;

    // Use two pointers to find the pairs of indices
    while (left < right) {
        int sum = x[left] + x[right];
        if (sum >= g - t && sum <= g + t) {
            // If the sum is within the range G-T to G+T (inclusive),
            // increment the count of pairs
            count++;
        }
        if (sum < g - t) {
            // If the sum is less than G-T, move the left pointer
            left++;
        } else if (sum > g + t) {
            // If the sum is greater than G+T, move the right pointer
            right--;
        }
    }

    cout << count << endl;

    return 0;
}
