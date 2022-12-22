#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // Read in the input and store it in a vector
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    // Sort the input vector
    sort(x.begin(), x.end());

    // Find the closest element to yi in the input vector
    for (int i = 0; i < m; i++) {
        int yi;
        cin >> yi;
        auto iter = lower_bound(x.begin(), x.end(), yi);

        // If yi is greater than the last element in the input vector,
        // the closest element is the last element
        if (iter == x.end()) {
            cout << x.back() << endl;
        }
        // If yi is smaller than the first element in the input vector,
        // the closest element is the first element
        else if (iter == x.begin()) {
            cout << x.front() << endl;
        }
        // If yi is between two elements in the input vector,
        // find the closest element among the two
        else {
            int upper = *iter;
            int lower = *(iter - 1);
            int cal_upper = abs(upper - yi);
            int cal_lower = abs(lower - yi);
            if (cal_upper < cal_lower) {
                cout << upper << endl;
            } else {
                cout << lower << endl;
            }
        }
    }
    return 0;
}