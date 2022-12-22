#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, g, t;
    cin >> n >> g >> t;

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    long long count = 0;
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = x[left] + x[right];
        if (g - t <= sum and  sum <= g + t) {
            count++;
        }
        if (sum < g - t) {
            left++;
        } else if (sum > g + t) {
            right--;
        } else {
            left++;
            right--;
        }
    }

    cout << count << endl;

    return 0;
}