#include <iostream>
#include <unordered_map>

int main() {
    // Read in the number of integers
    int n;
    std::cin >> n;

    // Use a hash map to store the frequency of each integer
    std::unordered_map<int, int> frequencies;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;

        // Increment the frequency of x in the hash map
        frequencies[x]++;
    }

    // Count the number of integers with a frequency of at least 3
    int count = 0;
    for (const auto& [x, frequency] : frequencies) {
        if (frequency >= 3) {
            count++;
        }
    }

    // Print the result
    std::cout << count << std::endl;

    return 0;
}